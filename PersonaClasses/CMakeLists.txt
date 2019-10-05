cmake_minimum_required(VERSION 2.6)
project(personaclasses)

add_executable(personaclasses main.cpp)

install(TARGETS personaclasses RUNTIME DESTINATION bin)
