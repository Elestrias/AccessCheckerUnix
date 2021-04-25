cmake_minimum_required(VERSION 3.19)
project(App)

set(CMAKE_CXX_STANDARD 20)
link_libraries(stdc++fs)

add_executable(App executable/main.cpp headers/dependencies.h executable/tools.cpp headers/tools.h executable/AccessChecker.cpp headers/AccessChecker.h)