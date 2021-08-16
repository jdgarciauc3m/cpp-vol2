cmake_minimum_required(VERSION 3.20)
project(primitive_vecnum_destr
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Werror -Wextra -pedantic -pedantic-errors)

add_executable(primitive_vecnum_destr main.cpp)
