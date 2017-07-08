cmake_minimum_required(VERSION 3.6)
project(monad)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Maybe.h)
add_executable(monad ${SOURCE_FILES})