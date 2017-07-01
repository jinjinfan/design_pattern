cmake_minimum_required(VERSION 3.6)
project(bridge)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp person.cpp person.h Shape.h)
add_executable(bridge ${SOURCE_FILES})