#include "fake_http_client.hpp"

std::string FakeHttpClient::get(std::string_view) {
    return R"({"main":{"temp":17.2,"unit":"C"}})";
}