cmake_minimum_required(VERSION 3.30)
project(HugeCplasplas LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS beast json)
find_package(GTest CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

# main executable
add_executable(HugeCplasplas
        src/main.cpp
        src/presentation/http_server.cpp
        src/infrastructure/providers/mock_provider.cpp
        src/application/weather_use_case.cpp
        src/presentation/http_router.cpp
)
target_link_libraries(HugeCplasplas PRIVATE Boost::beast Boost::json fmt::fmt)
target_include_directories(HugeCplasplas PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# unit-test executable
enable_testing()
add_executable(HugeCplasplas_tests tests/dummy_test.cpp)
target_link_libraries(HugeCplasplas_tests PRIVATE GTest::gtest GTest::gmock)
add_test(NAME unit COMMAND HugeCplasplas_tests)