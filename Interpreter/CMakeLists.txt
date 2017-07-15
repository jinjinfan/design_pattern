cmake_minimum_required(VERSION 3.7)
project(Interpreter)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Interpreter.h OverMath.h)
add_executable(Interpreter ${SOURCE_FILES})