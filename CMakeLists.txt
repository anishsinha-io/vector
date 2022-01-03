cmake_minimum_required(VERSION 3.20)
project(m C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(anish)
add_executable(m main.c)
target_link_libraries(m PRIVATE anish)