#pragma once
#include "src/domain/city.hpp"
#include "src/domain/weather.hpp"
#include "src/infrastructure/providers/i_weather_provider.hpp"
#include <string>

class OpenWeatherProvider : public IWeatherProvider {
public:
    explicit OpenWeatherProvider(std::string apiKey);
    std::optional<Weather> fetch(const City&) override;
private:
    std::string apiKey_;
};