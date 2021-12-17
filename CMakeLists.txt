cmake_minimum_required(VERSION 3.10)

project(Simulator)
enable_testing()

set(CMAKE_CXX_STANDARD 17)


find_package(Threads)

add_subdirectory(src)
add_subdirectory(test)
