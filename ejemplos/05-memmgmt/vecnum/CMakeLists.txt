cmake_minimum_required(VERSION 3.20)
project(vecnum)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)

add_executable(vecnum main.cpp vecnum.cpp)

find_package(GTest REQUIRED)

enable_testing()
add_executable(utest vecnum.cpp utest.cpp)
target_link_libraries(utest GTest::GTest GTest::Main)
gtest_discover_tests(utest)
