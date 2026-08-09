cmake_minimum_required(VERSION 3.5)

project (space_invaders)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib REQUIRED)
file(GLOB SOURCES "src/*.cpp")

add_executable (space_invaders ${SOURCES})

target_include_directories(space_invaders PRIVATE include)

target_link_libraries(space_invaders PRIVATE raylib)
