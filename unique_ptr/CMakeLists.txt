cmake_minimum_required(VERSION 3.14)
project(uniquePtr)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/52eb8108c5bdec04579160ae17225d66034bd723.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(uniquePtrTest unique_ptr_test.cpp)

target_link_libraries(uniquePtrTest PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(uniquePtrTest)
