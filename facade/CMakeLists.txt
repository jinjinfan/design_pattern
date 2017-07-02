cmake_minimum_required(VERSION 3.6)
project(facade)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Bloom.cpp
        Window.cpp
        Viewport.cpp
        TextBuffer.cpp)
add_executable(facade ${SOURCE_FILES})