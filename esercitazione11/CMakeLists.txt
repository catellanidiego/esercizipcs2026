cmake_minimum_required(VERSION 3.20)
project(esercitazione11)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Werror=vla")

enable_testing()

add_executable(test_de_pina test_de_pina.cpp)
add_test(NAME depina COMMAND test_de_pina)
