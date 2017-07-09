cmake_minimum_required(VERSION 3.7)
project(prototype)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Contact.h)
add_executable(prototype ${SOURCE_FILES})