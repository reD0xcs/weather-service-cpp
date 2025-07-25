#include "mock_provider.hpp"
#include "src/domain/city.hpp"
#include "src/domain/weather.hpp"

std::optional<Weather> MockProvider::fetch(const City&) {
    return Weather{42.0, 'C'};   // hard-coded for test
}