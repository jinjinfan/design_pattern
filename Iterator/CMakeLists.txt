cmake_minimum_required(VERSION 3.7)
project(iterator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BinaryTree.h SingleList.h)
add_executable(iterator ${SOURCE_FILES})