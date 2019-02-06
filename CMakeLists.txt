cmake_minimum_required(VERSION 2.6)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runBenchmarks benchmarks.cpp)
target_link_libraries(runBenchmarks benchmark pthread)
target_compile_options(runBenchmarks PRIVATE -O2)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
target_compile_options(runTests PRIVATE -O2)

