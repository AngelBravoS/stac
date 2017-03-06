cmake_minimum_required(VERSION 2.6)
project(stac)

add_executable(stac main.cpp)

install(TARGETS stac RUNTIME DESTINATION bin)
