cmake_minimum_required(VERSION 2.6)
set(CMAKE_C_COMPILER g++)

# Locate GTest
find_package(GTest REQUIRED)
INCLUDE_DIRECTORIES(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread lib
add_executable(test test.c proc_tools.c io_tools.c)
add_executable(app.exe main.c proc_tools.c io_tools.c)
target_link_libraries(test ${GTEST_LIBRARIES} pthread)


