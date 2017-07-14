cmake_minimum_required(VERSION 3.7)
project(command)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Account.h)
add_executable(command ${SOURCE_FILES})