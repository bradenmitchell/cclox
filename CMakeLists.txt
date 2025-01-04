cmake_minimum_required(VERSION 3.30)

project(cclox VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)

add_executable(lox)

add_subdirectory(src)
