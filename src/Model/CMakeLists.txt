cmake_minimum_required(VERSION 3.10)
project(src_Model)

set(CMAKE_CXX_STANDARD 17)

add_library(src_Model
        Board.h Game.h Lobby.h TileStateEnum.h TileEnum.h User.h Board.cpp Game.cpp Lobby.cpp TileEnum.cpp TileStateEnum.cpp)