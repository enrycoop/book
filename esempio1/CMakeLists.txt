cmake_minimum_required(VERSION 3.0)

project(esempio1)

add_executable(esempio1 main.cpp)

install(TARGETS esempio1 RUNTIME DESTINATION bin)
