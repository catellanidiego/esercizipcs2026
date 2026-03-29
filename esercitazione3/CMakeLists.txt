cmake_minimum_required(VERSION 3.20)
project(esercitazione3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(SOURCES es3.cpp header1.hpp header2.hpp)
add_executable(eseguibile3 ${SOURCES})