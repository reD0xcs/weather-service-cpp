#include "mock_provider.hpp"
#include "src/domain/city.hpp"
#include "src/domain/weather.hpp"

std::optional<Weather> MockProvider::fetch(const City&) {
    return Weather{23.5, 'C'};
}