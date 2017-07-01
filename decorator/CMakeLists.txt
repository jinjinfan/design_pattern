cmake_minimum_required(VERSION 3.6)
project(decorator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Logger.h Geometry.h)
add_executable(decorator ${SOURCE_FILES})