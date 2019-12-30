cmake_minimum_required(VERSION 3.10)
project(src_Client)

set(CMAKE_CXX_STANDARD 17)

add_executable(src_Client
        ViewToClient.h
        Client.cpp Client.h MessageType.h)
