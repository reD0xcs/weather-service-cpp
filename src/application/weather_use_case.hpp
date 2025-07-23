#pragma once
#include "src/domain/city.hpp"
#include "src/domain/weather.hpp"
#include "src/infrastructure/providers/i_weather_provider.hpp"
#include <memory>

class WeatherUseCase {
public:
    explicit WeatherUseCase(std::unique_ptr<IWeatherProvider>);
    Weather execute(const City&);
private:
    std::unique_ptr<IWeatherProvider> provider_;
};