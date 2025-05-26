cmake_minimum_required(VERSION 3.27)
project(swap)

set(CMAKE_CXX_STANDARD 17)

add_executable(swap main.cpp
        array.cpp
        array.h)
