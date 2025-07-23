#pragma once
#include "i_weather_provider.hpp"
#include "../../domain/city.hpp"
#include "../../domain/weather.hpp"
#include <optional>


class MockProvider : public IWeatherProvider {
public:
    std::optional<Weather> fetch(const City&) override;
};