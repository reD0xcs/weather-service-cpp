#pragma once
#include "../../domain/city.hpp"
#include "../../domain/weather.hpp"
#include <optional>

class IWeatherProvider {
public:
    virtual ~IWeatherProvider() = default;
    virtual std::optional<Weather> fetch(const City&) = 0;
};