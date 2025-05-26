cmake_minimum_required(VERSION 3.30)
project(stoskolejka_lista)

set(CMAKE_CXX_STANDARD 17)

add_executable(stoskolejka_lista main.cpp
        lista.cpp
        lista.h)
