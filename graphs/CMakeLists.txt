cmake_minimum_required(VERSION 3.19)
project(graphs)

set(CMAKE_CXX_STANDARD 17)

add_executable(graphs graphs.cpp)

include_directories(source)