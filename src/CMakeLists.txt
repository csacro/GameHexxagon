cmake_minimum_required(VERSION 3.10)
project(GameHexxagon_src)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Client)
add_subdirectory(DataHandler)
add_subdirectory(ViewHandler)
add_subdirectory(Views)
add_subdirectory(Model)

add_executable(GameHexxagon_src main.cpp)

target_link_libraries(GameHexxagon_src src_Model)
#TODO install and link SFMLComponents
#TODO link nlohmann-json
#TODO link SFML
#TODO find WebSocket
