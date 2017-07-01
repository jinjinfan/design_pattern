cmake_minimum_required(VERSION 3.6)
project(composite)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Expression.h Geometry.h Neuron.h)
add_executable(composite ${SOURCE_FILES})