cmake_minimum_required(VERSION 3.12)
project(IT2)
set(CMAKE_CXX_STANDARD 11)

set(EXEC_NAME test)
set(SHOW_COV_EXE ${EXEC_NAME}_cov)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Create static lib for simpleAvg
add_library(simpleAvg STATIC simpleAvg.cpp)

# Create shared lib for parallelAvg
add_library(parallelAvg SHARED parallelAvg.cpp)

add_executable(${EXEC_NAME} main.cpp)
target_link_libraries(${EXEC_NAME} simpleAvg)
target_link_libraries(${EXEC_NAME} parallelAvg)
target_link_libraries(${EXEC_NAME} ${GTEST_LIBRARIES} pthread)


add_executable(${SHOW_COV_EXE} main.cpp)
target_link_libraries(${SHOW_COV_EXE} simpleAvg)
target_link_libraries(${SHOW_COV_EXE} parallelAvg)
target_link_libraries(${SHOW_COV_EXE} ${GTEST_LIBRARIES} pthread)
target_compile_options(${SHOW_COV_EXE} -fprofile-arcs -ftest-coverage)
