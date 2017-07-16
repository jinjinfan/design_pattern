cmake_minimum_required(VERSION 3.7)
project(Mediator)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Person.cpp Person.h ChatRoom.cpp ChatRoom.h Mediator.h)
add_executable(Mediator ${SOURCE_FILES})