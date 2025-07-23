#include "weather_use_case.hpp"
#include "../domain/city.hpp"
#include "../domain/weather.hpp"
#include "../infrastructure/providers/i_weather_provider.hpp"

WeatherUseCase::WeatherUseCase(std::unique_ptr<IWeatherProvider> p)
    : provider_(std::move(p)) {}
Weather WeatherUseCase::execute(const City& c) {
    return provider_->fetch(c).value_or(Weather{0, 'C'});
}