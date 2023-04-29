cmake_minimum_required(VERSION 3.25)
project(labb3_v1)

set(CMAKE_CXX_STANDARD 23)

add_executable(labb3_v1 main.cpp node.h algorithms.cpp algorithms.h datagenerator.cpp datagenerator.h measurement.cpp measurement.h run_search.cpp run_search.h)
