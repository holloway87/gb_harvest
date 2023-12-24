cmake_minimum_required(VERSION 3.27)
project(gb_harvest C)

set(CMAKE_C_STANDARD 23)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.c")
file(GLOB_RECURSE RESOURCES RELATIVE ${CMAKE_SOURCE_DIR} "res/*.c")

add_executable(gb_harvest ${SOURCES} ${RESOURCES})

target_include_directories(gb_harvest PUBLIC ~/Programs/gbdk/include)
