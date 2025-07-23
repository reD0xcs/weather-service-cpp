#include "http_router.hpp"
#include <boost/json/src.hpp>
#include <boost/json/object.hpp>
#include <boost/json/serialize.hpp>
#include "src/presentation/http_router.hpp"
#include <sstream>

std::string url_decode(std::string_view in) {
    std::string out; out.reserve(in.size());
    for (size_t i = 0; i < in.size(); ++i) {
        if (in[i] == '%' && i + 2 < in.size()) {
            int v; sscanf(in.substr(i + 1, 2).data(), "%2x", &v);
            out += static_cast<char>(v); i += 2;
        } else if (in[i] == '+') {
            out += ' ';
        } else {
            out += in[i];
        }
    }
    return out;
}

std::string make_json_response(std::string_view city, double temp) {
    boost::json::object obj{{"city", url_decode(city)},
                            {"temperature", temp},
                            {"unit", 'C'}};
    return boost::json::serialize(obj);
}