cmake_minimum_required(VERSION 3.26)
project(Listonic)

set(CMAKE_CXX_STANDARD 17)

add_executable(Listonic main.cpp
        ShoppingItem.cpp
        ShoppingItem.h)
