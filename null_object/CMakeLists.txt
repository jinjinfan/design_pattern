cmake_minimum_required(VERSION 3.6)
project(null_object)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BankAccount.h)
add_executable(null_object ${SOURCE_FILES})