cmake_minimum_required(VERSION 3.19)
project(GEMS)

set(CMAKE_CXX_STANDARD 20)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(gemes main.cpp Block.cpp Block.h Game.cpp Game.h)
target_link_libraries(gemes sfml-graphics sfml-audio)