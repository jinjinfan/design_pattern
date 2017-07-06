cmake_minimum_required(VERSION 3.6)
project(specification)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp LSP.h OCP.h ISP.h DI.h)
add_executable(specification ${SOURCE_FILES})