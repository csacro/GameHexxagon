cmake_minimum_required(VERSION 3.10)
project(GameHexxagon_test)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(googletest)

add_executable(GameHexxagon_test main.cpp GameLogic.cpp Network.cpp)
target_link_libraries(GameHexxagon_test gtest gmock pthread)
