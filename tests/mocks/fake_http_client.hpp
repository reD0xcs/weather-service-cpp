#pragma once
#include <string>
#include <string_view>

struct FakeHttpClient {
    std::string get(std::string_view url);
};