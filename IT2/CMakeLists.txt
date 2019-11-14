cmake_minimum_required(VERSION 3.12)
project(IT2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

set(TEST_NAME test.exe)
set(EXEC_NAME app.exe)
set(EXPERIMENT_NAME experiment.exe)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Create static lib for simpleAvg
add_library(simpleAvg STATIC simple_avg.cpp)

# Create shared lib for parallelAvg
add_library(parallelAvg SHARED parallel_avg.cpp)
target_link_libraries(parallelAvg pthread simpleAvg)

# add product executable
add_executable(${EXEC_NAME} main.cpp)
target_link_libraries(${EXEC_NAME} dl)
set_target_properties(${EXEC_NAME} PROPERTIES COMPILE_FLAGS "-O3 -DNDEBUG")


# add test executable
add_executable(${TEST_NAME} test.cpp)
set_target_properties(${TEST_NAME} PROPERTIES COMPILE_FLAGS "-g3 -O0 -fprofile-arcs -ftest-coverage")
set_target_properties(${TEST_NAME} PROPERTIES LINK_FLAGS "--coverage")
target_link_libraries(${TEST_NAME} simpleAvg)
target_link_libraries(${TEST_NAME} parallelAvg)
target_link_libraries(${TEST_NAME} ${GTEST_LIBRARIES} pthread)

# add experiment executable
add_executable(${EXPERIMENT_NAME} experiment.cpp)
target_link_libraries(${EXPERIMENT_NAME} simpleAvg)
target_link_libraries(${EXPERIMENT_NAME} parallelAvg)

