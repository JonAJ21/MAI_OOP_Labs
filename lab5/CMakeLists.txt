cmake_minimum_required(VERSION 3.10)
project(lab_5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(googletest)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
# set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)

include_directories(${INCLUDE_DIR})

# file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false ${SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false ${TEST_DIR}/*.cpp)

# add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCES})
add_executable(${CMAKE_PROJECT_NAME}_exe main.cpp)
add_executable(${CMAKE_PROJECT_NAME}_tests ${TEST_SOURCES})

# target_link_libraries(${CMAKE_PROJECT_NAME}_exe PRIVATE ${CMAKE_PROJECT_NAME}_lib)
target_include_directories(${CMAKE_PROJECT_NAME}_tests PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
# target_link_libraries(${CMAKE_PROJECT_NAME}_tests PRIVATE ${CMAKE_PROJECT_NAME}_lib gtest gtest_main)
target_link_libraries(${CMAKE_PROJECT_NAME}_tests PRIVATE gtest gtest_main)

add_test(NAME BASIC COMMAND test_01)


