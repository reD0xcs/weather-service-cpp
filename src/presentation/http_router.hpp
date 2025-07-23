#pragma once
#include <string>
#include <string_view>

std::string url_decode(std::string_view in);
std::string make_json_response(std::string_view city, double temp);