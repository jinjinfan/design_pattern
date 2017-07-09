cmake_minimum_required(VERSION 3.6)
project(Builder)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp HTMLBuilder.h GroovyStyle.h
        Person.cpp Person.h
        PersonBuilder.cpp PersonBuilder.h
        PersonAddressBuilder.cpp PersonAddressBuilder.h
        PersonJobBuilder.cpp PersonJobBuilder.h)
add_executable(Builder ${SOURCE_FILES})