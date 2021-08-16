cmake_minimum_required(VERSION 3.20)
project(vecnum_copy)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)

add_executable(vecnum_copy main.cpp vecnum.cpp vecnum.hpp)
