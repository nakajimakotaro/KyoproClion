cmake_minimum_required(VERSION 3.10)
project(KyoproCppClion)

set(CMAKE_CXX_STANDARD 14)
set(Boost_USE_STATIC_LIBS ON)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(main kyopro.cpp)
add_executable(test kyopro.cpp test.cpp)

target_link_libraries(main ${Boost_LINKS})
target_link_libraries(test ${Boost_LINKS} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

target_compile_definitions(main PRIVATE LOCAL)
target_compile_definitions(test PRIVATE TEST)
