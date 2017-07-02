cmake_minimum_required(VERSION 3.6)
project(flyweight)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Window.cpp
        Viewport.cpp
        TextBuffer.cpp
        main.cpp
        User.h)
add_executable(flyweight ${SOURCE_FILES})