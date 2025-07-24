#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "src/application/weather_use_case.hpp"
#include "src/infrastructure/providers/mock_provider.hpp"

using ::testing::Return;

class MockProvider : public IWeatherProvider {
public:
    MOCK_METHOD(std::optional<Weather>, fetch, (const City&), (override));
};

TEST(WeatherUseCase, returnsMockedTemp) {
    auto mock = std::make_unique<MockProvider>();
    EXPECT_CALL(*mock, fetch(City{"Berlin"}))
        .WillOnce(Return(Weather{42.0, 'C'}));

    WeatherUseCase uc{std::move(mock)};
    auto w = uc.execute({"Berlin"});
    EXPECT_DOUBLE_EQ(w.temperature, 42.0);
}