cmake_minimum_required(VERSION 3.12)
project(IT2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-O0 -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

set(EXEC_NAME test.exe)

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


#add_executable(${SHOW_COV_EXE} main.cpp)
#target_link_libraries(${SHOW_COV_EXE} simpleAvg)
#target_link_libraries(${SHOW_COV_EXE} parallelAvg)
#target_link_libraries(${SHOW_COV_EXE} ${GTEST_LIBRARIES} pthread)
#target_compile_options(${SHOW_COV_EXE} PRIVATE -fprofile-arcs PRIVATE -ftest-coverage)
#target_link_options(${SHOW_COV_EXE} PRIVATE -lgcov PRIVATE --coverage)
