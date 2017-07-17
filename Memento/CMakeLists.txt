cmake_minimum_required(VERSION 3.7)
project(Memento)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Memento.h)
add_executable(Memento ${SOURCE_FILES})