cmake_minimum_required(VERSION 3.6)
project(hax)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fpermissive -llua")
set(SOURCE_FILES main.cpp Computer/Computer.cpp Computer/Computer.h Network/Network.cpp Network/Network.h Config/Config.cpp Config/Config.h User/User.cpp User/User.h)
add_executable(hax ${SOURCE_FILES})