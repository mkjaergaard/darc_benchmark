cmake_minimum_required(VERSION 2.8)
project(darc_examples)

find_package(darc)
find_package(ROS COMPONENTS std_msgs)

include_directories(include)
include_directories(${darc_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "-Os")

add_subdirectory(procedure_ping)
