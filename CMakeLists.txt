cmake_minimum_required(VERSION 3.26)
project(Listonic)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)

set(SOURCE_FILES ShoppingItem.cpp ShoppingItem.h)
add_executable(Listonic main.cpp ShoppingItem.cpp
        ShoppingList.cpp
        ShoppingList.h)
add_library(core ${SOURCE_FILES})
target_link_libraries(Listonic core)