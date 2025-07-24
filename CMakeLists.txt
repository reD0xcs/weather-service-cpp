cmake_minimum_required(VERSION 3.30)
project(weather-service-cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Boost REQUIRED COMPONENTS beast json)
find_package(GTest CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

# ----------------- SERVER -----------------
add_executable(server
        src/main.cpp
        src/presentation/http_server.cpp
        src/presentation/http_router.cpp
        src/application/weather_use_case.cpp
        src/infrastructure/providers/mock_provider.cpp
)
target_link_libraries(server PRIVATE Boost::beast Boost::json fmt::fmt)
target_include_directories(server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# ----------------- UNIT TESTS -------------
enable_testing()
include(GoogleTest)
add_executable(unit_tests
        tests/dummy_test.cpp
        tests/weather_use_case_test.cpp
        src/application/weather_use_case.cpp
        src/infrastructure/providers/mock_provider.cpp
)
target_link_libraries(unit_tests PRIVATE GTest::gtest GTest::gmock)
target_include_directories(unit_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
include(GoogleTest)
gtest_discover_tests(unit_tests)

# ----------------- GLOBAL -----------------
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)