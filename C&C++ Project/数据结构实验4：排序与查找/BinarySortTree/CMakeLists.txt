cmake_minimum_required(VERSION 3.28.1)
project(BinarySortTree)

set(CMAKE_CXX_STANDARD 20)

link_libraries(libeasyx.a)
add_executable(BinarySortTree main.cpp YXbitree.h YXqueue.h YXstack.h
)
