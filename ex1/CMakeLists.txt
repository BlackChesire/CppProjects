cmake_minimum_required(VERSION 3.17)
project(ex1)

set(CMAKE_CXX_STANDARD 98)

add_executable(ex1 main.cpp BoardList.h BoardList.cpp Board.h Board.cpp)