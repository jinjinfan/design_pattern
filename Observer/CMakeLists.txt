cmake_minimum_required(VERSION 3.7)
project(Observer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Observer.h Observer2.h)
add_executable(Observer ${SOURCE_FILES})