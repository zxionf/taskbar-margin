cmake_minimum_required(VERSION 3.15)
project(taskbar)

set(CMAKE_CXX_STANDARD 20)
set(ARCH "x64")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc -static-libstdc++")
add_executable(tb taskbar.cpp)