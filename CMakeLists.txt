cmake_minimum_required(VERSION 2.6)
set(CMAKE_C_COMPILER g++)

# Locate GTest
INCLUDE_DIRECTORIES(${GTEST_INCLUDE_DIRS})
find_package(GTest REQUIRED)

# Link runTests with what we want to test and the GTest and pthread lib
add_executable(runTests.exe test.c proc_tools.c io_tools.c)
target_link_libraries(runTests.exe ${GTEST_LIBRARIES} pthread)


