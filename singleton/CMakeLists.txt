cmake_minimum_required(VERSION 3.7)
project(singleton)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SingletonDatabase.h)
add_executable(singleton ${SOURCE_FILES})