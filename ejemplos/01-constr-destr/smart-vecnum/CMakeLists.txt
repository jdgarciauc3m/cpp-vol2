cmake_minimum_required(VERSION 3.20)
project(smart-vecnum)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)

add_executable(smart_vecnum main.cpp)
