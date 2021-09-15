cmake_minimum_required(VERSION 3.20)
project(hello_world_cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_TOOLCHAIN_FILE )

add_executable(hello_world_cpp src/main.cpp src/hwcppstddef.h)