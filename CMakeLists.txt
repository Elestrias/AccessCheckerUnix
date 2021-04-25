cmake_minimum_required(VERSION 3.19)
project(App)

set(CMAKE_CXX_STANDARD 20)
link_libraries(stdc++fs)

add_executable(App main.cpp main.cpp dependencies.h)