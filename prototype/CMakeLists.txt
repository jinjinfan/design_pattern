cmake_minimum_required(VERSION 3.7)
project(prototype)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Contact.h Serialization.h)
find_package(Boost 1.60.0 COMPONENTS system serialization REQUIRED)

if(Boost_FOUND)

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR})

endif()

if(Boost_FOUND)
    add_executable(prototype ${SOURCE_FILES})
    target_link_libraries(prototype ${Boost_LIBRARIES})
endif()
