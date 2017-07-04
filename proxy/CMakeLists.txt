cmake_minimum_required(VERSION 3.6)
project(proxy)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BankAccount.h VirtualProxy.h CommuProxy.h)
add_executable(proxy ${SOURCE_FILES})