#define _WIN32_WINNT 0x0601

#include "http_server.hpp"
#include "http_router.hpp"
#include "src/application/weather_use_case.hpp"
#include "src/infrastructure/providers/mock_provider.hpp"
#include <boost/beast.hpp>
#include <boost/asio.hpp>
#include <fmt/core.h>

namespace beast = boost::beast;
namespace http  = beast::http;
namespace net   = boost::asio;
using tcp       = net::ip::tcp;

int run_server() {
    net::io_context ioc{1};
    tcp::acceptor acceptor{ioc, {net::ip::make_address("0.0.0.0"), 8080}};
    fmt::println("Listening on 0.0.0.0:8080");

    WeatherUseCase useCase{std::make_unique<MockProvider>()};

    for (;;) {
        tcp::socket socket{ioc};
        acceptor.accept(socket);

        beast::flat_buffer buffer;
        http::request<http::string_body> req;
        http::read(socket, buffer, req);

        std::string city = "unknown";
        std::string_view target = req.target();
        if (target.starts_with("/weather?city=")) {
            size_t begin = 14;
            size_t end   = target.find('&', begin);
            city = target.substr(begin, end - begin);
        }

        Weather w = useCase.execute({city});
        auto json = make_json_response(city, w.temperature);

        http::response<http::string_body> res{http::status::ok, req.version()};
        res.set(http::field::content_type, "application/json");
        res.body() = json;
        http::write(socket, res);
    }
    return 0;
}