#include "open_weather_provider.hpp"
#include <boost/beast.hpp>
#include <boost/json.hpp>

namespace beast = boost::beast;
namespace http  = beast::http;
namespace net   = boost::asio;
using tcp       = net::ip::tcp;

std::optional<Weather> OpenWeatherProvider::fetch(const City& city) {
    try {
        const std::string host = "api.open-meteo.com";
        const std::string port = "80";               // HTTP (no SSL)
        // Build latitude/longitude – you can hard-code or geocode later
        const std::string target =
            "/v1/forecast?latitude=52.52&longitude=13.41&current=temperature_2m";

        net::io_context ioc;
        tcp::socket socket{ioc};
        tcp::resolver resolver{ioc};
        auto const results = resolver.resolve(host, port);
        net::connect(socket, results.begin(), results.end());

        http::request<http::string_body> req{http::verb::get, target, 11};
        req.set(http::field::host, host);
        req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
        http::write(socket, req);

        beast::flat_buffer buffer;
        http::response<http::dynamic_body> res;
        http::read(socket, buffer, res);

        auto jv = boost::json::parse(beast::buffers_to_string(res.body().data()));
        double temp = jv.at("current").at("temperature_2m").as_double();
        return Weather{temp, 'C'};

    } catch (...) {
        return std::nullopt;
    }
}