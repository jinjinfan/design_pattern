cmake_minimum_required(VERSION 3.7)
project(Visitor)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Visitor.cpp Visitor.h Model.h MultipleDispatch.h)
add_executable(Visitor ${SOURCE_FILES})