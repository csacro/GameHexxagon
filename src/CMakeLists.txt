cmake_minimum_required(VERSION 3.10)
project(GameHexxagon_src)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Client)
add_subdirectory(DataHandler)
add_subdirectory(ViewHandler)
add_subdirectory(Views)
add_subdirectory(Model)

add_executable(GameHexxagon_src main.cpp)

target_link_libraries(GameHexxagon_src
        src_Model src_Client src_DataHandler src_ViewHandler src_Views
        sfml-graphics sfml-window sfml-system)
#TODO find WebSocket
