cmake_minimum_required(VERSION 3.20)
project(vecnum_smart)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)

add_executable(vecnum_smart main.cpp vecnum.cpp vecnum.hpp)

enable_testing()
add_subdirectory(utest)
