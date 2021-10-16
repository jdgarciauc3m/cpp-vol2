cmake_minimum_required(VERSION 3.20)
project(vecval)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)

add_executable(vecval main.cpp vecval.hpp)

add_subdirectory(utest)
