cmake_minimum_required(VERSION 3.7)
project(chain_of_responsibility)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Creature.h Creature2.h)
add_executable(chain_of_responsibility ${SOURCE_FILES})