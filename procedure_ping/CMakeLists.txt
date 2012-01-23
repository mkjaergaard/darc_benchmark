cmake_minimum_required(VERSION 2.8)
project(pubsub1)

include_directories(include)
include_directories(${darc_INCLUDE_DIRS})
include_directories(${ROS_INCLUDE_DIRS})

set(CMAKE_EXE_LINKER_FLAGS "-pg")
set(CMAKE_CXX_FLAGS "-Os -pg")

add_executable(procedure_ping_node src/procedure_ping_node.cpp src/ping_component.cpp src/pong_component.cpp)
target_link_libraries(procedure_ping_node ${darc_LIBRARIES} ${ROS_LIBRARIES})

darc_pybindings(PingComponent src/ping_component.cpp)
darc_pybindings(PongComponent src/pong_component.cpp)
