cmake_minimum_required(VERSION 3.10)
project(src_ViewHandler)

set(CMAKE_CXX_STANDARD 17)

add_library(src_ViewHandler
        DataToView.h
        GameviewToView.h LobbyoverviewToView.h LobbyviewToView.h MainmenuToView.h
        ViewHandler.cpp ViewHandler.h)
