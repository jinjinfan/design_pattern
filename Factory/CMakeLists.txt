cmake_minimum_required(VERSION 3.7)
project(Factory)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Point.h HotDrink.h CoffeeFactory.h HotDrinkFactory.h TeaFactory.h DrinkFactory.h)
add_executable(Factory ${SOURCE_FILES})