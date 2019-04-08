cmake_minimum_required (VERSION 2.6)
project (RayTracer)
#include_directories (src)
set(SOURCES src/main.cpp src/Tuple.cpp)
set(TESTSOURCES src/test.cpp src/Tuple.cpp)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

find_package(Boost)
IF (Boost_FOUND)
include_directories(${Boost_INCLUDE_DIR})
endif()

add_executable(Main ${SOURCES})
add_executable(TestMain ${TESTSOURCES})
target_link_libraries(TestMain boost_unit_test_framework)
