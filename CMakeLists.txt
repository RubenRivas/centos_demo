cmake_minimum_required(VERSION 2.8)
project(demo)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp split_log.h)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libstdc++")
# set(CMAKE_EXE_LINKER_FLAGS 
