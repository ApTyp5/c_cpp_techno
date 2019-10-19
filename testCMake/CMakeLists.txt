cmake_minimum_required(VERSION 3.13)
project(test)

add_library(lib SHARED hello.cpp)
add_library(lib2 STATIC hello2.cpp)

add_executable(main main.cpp)

target_link_libraries(main lib)
target_link_libraries(main lib2)

