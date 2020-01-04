cmake_minimum_required(VERSION 3.10)
project(src_DataHandler)

set(CMAKE_CXX_STANDARD 17)

add_library(src_DataHandler
        ClientToData.h
        ViewToData.h
        DataHandler.cpp DataHandler.h)
