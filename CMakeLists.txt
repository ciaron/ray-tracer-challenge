cmake_minimum_required (VERSION 2.6)
project (RayTracer)
#include_directories (src)
set(CHAPTER1_SOURCES src/chapter1.cpp src/Tuple.cpp)
set(CHAPTER1_TESTSOURCES src/chapter1_test.cpp src/Tuple.cpp)

set(CHAPTER2_SOURCES src/chapter2.cpp src/Tuple.cpp src/Canvas.cpp)
set(CHAPTER2_TESTSOURCES src/chapter2_test.cpp src/Tuple.cpp src/Canvas.cpp)

set(CHAPTER3_SOURCES src/chapter3.cpp src/Matrix.cpp src/Tuple.cpp)
set(CHAPTER3_TESTSOURCES src/chapter3_test.cpp src/Matrix.cpp src/Tuple.cpp)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

find_package(Boost)
IF (Boost_FOUND)
include_directories(${Boost_INCLUDE_DIR})
endif()

add_executable(chapter1 ${CHAPTER1_SOURCES})
add_executable(test_chapter1 ${CHAPTER1_TESTSOURCES})
target_link_libraries(test_chapter1 boost_unit_test_framework)

add_executable(chapter2 ${CHAPTER2_SOURCES})
add_executable(test_chapter2 ${CHAPTER2_TESTSOURCES})
target_link_libraries(test_chapter2 boost_unit_test_framework)

add_executable(chapter3 ${CHAPTER3_SOURCES})
add_executable(test_chapter3 ${CHAPTER3_TESTSOURCES})
target_link_libraries(test_chapter3 boost_unit_test_framework)
