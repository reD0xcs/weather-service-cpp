#include "open_weather_provider.hpp"
#include "src/domain/city.hpp"
#include "src/domain/weather.hpp"
#include "src/infrastructure/providers/i_weather_provider.hpp"
#include <sstream>

OpenWeatherProvider::OpenWeatherProvider(std::string apiKey)
    : apiKey_(std::move(apiKey)) {}

std::optional<Weather> OpenWeatherProvider::fetch(const City& c) {
    // TODO: real HTTP call; for now mock JSON
    return Weather{17.2, 'C'};
}