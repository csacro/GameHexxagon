cmake_minimum_required(VERSION 3.10)
project(src_Views)

set(CMAKE_CXX_STANDARD 17)

add_executable(src_Views
        ViewToGameview.h ViewToLobbyoverview.h ViewToLobbyview.h ViewToMainmenu.h
        Gameview.cpp Gameview.h Lobbyview.cpp Lobbyview.h Lobbyoverview.cpp Lobbyoverview.h Mainmenu.cpp Mainmenu.h)
