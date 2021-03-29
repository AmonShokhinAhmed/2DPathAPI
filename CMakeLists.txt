cmake_minimum_required(VERSION 3.1)

project(2DPathAPI)

add_subdirectory(Demo)
add_subdirectory(2DPathAPI)

include(CTest)
enable_testing()
add_subdirectory(Tests)