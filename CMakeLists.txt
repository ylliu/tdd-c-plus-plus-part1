cmake_minimum_required(VERSION 3.24)
project(tdd_c_plus_plus_part_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(tdd_c_plus_plus_part_1 tests/main.cpp Test.h tests/Creation.cpp tests/Confirm.cpp)
