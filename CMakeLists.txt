cmake_minimum_required(VERSION 3.25)
project(color_wars)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib REQUIRED)

add_executable(color_wars
    src/main.cpp
    src/cell/cell.cpp)

target_link_libraries(color_wars PRIVATE raylib)
