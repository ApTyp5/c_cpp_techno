cmake_minimum_required(VERSION 2.6)
set(CMAKE_C_COMPILER g++)
set(CMAKE_C_FLAGS "-O0 -fprofile-arcs -ftest-coverage")
set(CMAKE_C_OUTPUT_EXTENSION_REPLACE 1)

# Locate GTest
find_package(GTest REQUIRED)
INCLUDE_DIRECTORIES(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread lib
add_executable(test.exe test.c proc_tools.c io_tools.c)
target_link_libraries(test.exe ${GTEST_LIBRARIES} pthread)


