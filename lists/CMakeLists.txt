cmake_minimum_required(VERSION 3.0)

project(lists)

add_executable(lists main.cpp)

install(TARGETS lists RUNTIME DESTINATION bin)
