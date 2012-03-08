add_executable(procedure_ping_node src/procedure_ping_node.cpp src/ping_component.cpp src/pong_component.cpp)
target_link_libraries(procedure_ping_node ${darc_LIBRARIES})

darc_pybindings(PingComponent src/ping_component.cpp)
darc_pybindings(PongComponent src/pong_component.cpp)
