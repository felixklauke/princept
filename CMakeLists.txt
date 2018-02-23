cmake_minimum_required(VERSION 3.9)
project(princept)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(princept main.cpp src/Lexer.cpp include/Lexer.h)