cmake_minimum_required(VERSION 3.6)
project(specification)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Product.h Rectangle.h)
add_executable(specification ${SOURCE_FILES})