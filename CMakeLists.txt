cmake_minimum_required (VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

find_package(Boost 1.35.0 REQUIRED random program_options)
include_directories(${Boost_INCLUDE_DIRS})

add_executable (multirng main.cpp)
target_link_libraries(multirng ${Boost_LIBRARIES})