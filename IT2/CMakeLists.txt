cmake_minimum_required(VERSION 2.6)
project(IT2)

set(CMAKE_CXX_COMPILER g++)
set(simpleAvgLib libsimpleAvg.a)
set(paralledAvgLib libparallelAvg.so)
set(LIBS ${simpleAvgLib} ${paralledAvgLib} 
         ${GTEST_LIBRARIES} pthread}
set(SOURCES main.cpp)

# Locate GTest
find_package(GTest REQUIRED)
INCLUDE_DIRECTORIES(${GTEST_INCLUDE_DIRS})

# Create static lib for simpleAvg
add_library(${simpleAvgLib} STATIC simpleAvg.cpp)

# Create shared lib for paralledAvg
add_library(${paralledAvgLib} SHARED paralledAvg.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBS})


