cmake_minimum_required(VERSION 3.20)
project(esercitazione2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

add_executable(eseguibile211 es2parte1punto1.cpp)
add_executable(eseguibile212 es2parte1punto2.cpp)
add_executable(eseguibile22 es2parte2.cpp)
add_executable(eseguibile23 es2parte3.cpp)