cmake_minimum_required(VERSION 3.14)
project(allocatorTests)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/52eb8108c5bdec04579160ae17225d66034bd723.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(allocatorTest allocator_tests.cpp)

target_link_libraries(allocatorTest PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(allocatorTest)
