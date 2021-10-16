cmake_minimum_required(VERSION 3.20)
project(array)

set(CMAKE_CXX_STANDARD 11)
add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)

add_executable(array main.cpp array.hpp)
