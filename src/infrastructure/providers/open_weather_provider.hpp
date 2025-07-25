#pragma once
#include "src/domain/city.hpp"
#include "src/domain/weather.hpp"
#include "src/infrastructure/providers/i_weather_provider.hpp"
#include <string>

class OpenWeatherProvider final : public IWeatherProvider {
public:
    explicit OpenWeatherProvider(std::string_view apiKey);
    std::optional<Weather> fetch(const City& city) override;
private:
    std::string apiKey_;
};