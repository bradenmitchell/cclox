cmake_minimum_required(VERSION 3.28)

project(CCLox VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)

add_executable(lox)

add_subdirectory(src)
