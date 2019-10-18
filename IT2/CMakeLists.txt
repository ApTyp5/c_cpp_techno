cmake_minimum_required(VERSION 2.6)
project(IT2)

set(CMAKE_CXX_COMPILER g++)
set(simpleAvgLib simpleAvg)
set(paralledAvgLib parallelAvg)
set(SOURCES main.cpp)
#set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})

# Locate GTest
find_package(GTest REQUIRED)
INCLUDE_DIRECTORIES(${GTEST_INCLUDE_DIRS})

# Create static lib for simpleAvg
add_library(${simpleAvgLib} STATIC simpleAvg.cpp)

# Create shared lib for paralledAvg
add_library(${paralledAvgLib} SHARED parallelAvg.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} ${simpleAvgLib} pthread ${paralledAvgLib})


