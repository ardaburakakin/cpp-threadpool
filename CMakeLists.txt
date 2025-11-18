cmake_minimum_required(VERSION 3.10)
project(cpp_threadpool LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp_threadpool
    src/main.cpp
    src/ThreadPool.cpp
)

target_include_directories(cpp_threadpool PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
