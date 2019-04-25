cmake_minimum_required (VERSION 2.6)
project (RayTracer)
#include_directories (src)
set(CHAPTER1_SOURCES src/chapter1.cpp src/Tuple.cpp)
set(CHAPTER1_TESTSOURCES src/chapter1_test.cpp src/Tuple.cpp)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

find_package(Boost)
IF (Boost_FOUND)
include_directories(${Boost_INCLUDE_DIR})
endif()

add_executable(chapter1 ${CHAPTER1_SOURCES})
add_executable(test_chapter1 ${CHAPTER1_TESTSOURCES})
target_link_libraries(test_chapter1 boost_unit_test_framework)
