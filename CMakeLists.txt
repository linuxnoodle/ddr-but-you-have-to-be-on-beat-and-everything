cmake_minimum_required(VERSION 3.17)
project(DDRBYHTBOBAE)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")
SET(CMAKE_CXX_FLAGS "-Wall -O2 -std=c++17")
SET(CMAKE_EXE_LINKER_FLAGS "-lSDL2 -lSDL2_image")

add_executable(ddr-but-you-have-to-be-on-beat-and-everything ${SOURCES})
