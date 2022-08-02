cmake_minimum_required(VERSION 3.0.0)
project(cpp-extended-library VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

include_directories(src/cpp-extended-library)

add_executable(unit_test
    test/unit_test.cpp
    src/cpp-extended-library/fraction.hpp
    src/cpp-extended-library/combinatorics.hpp
)
