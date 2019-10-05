cmake_minimum_required(VERSION 2.6)
project(persona)

add_executable(persona main.cpp)

install(TARGETS persona RUNTIME DESTINATION bin)
