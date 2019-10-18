cmake_minimum_required(VERSION 3.13)
project(IT2)

# Locate GTest
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_BINARY_DIR})

# Create static lib for simpleAvg
add_library(simpleAvg STATIC simpleAvg.cpp)

# Create shared lib for parallelAvg
add_library(parallelAvg SHARED parallelAvg.cpp)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread)
target_link_libraries(${PROJECT_NAME} parallelAvg)
target_link_libraries(${PROJECT_NAME} simpleAvg)


