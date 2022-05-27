cmake_minimum_required(VERSION 3.21)
project(electrification)

set(CMAKE_CXX_STANDARD 23)

add_executable(electrification main.cpp structures.h electrification.h electrification.cpp)
