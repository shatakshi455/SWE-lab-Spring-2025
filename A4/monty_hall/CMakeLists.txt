# Required for compatibility reasons
cmake_minimum_required(VERSION 3.10)
# Name of the project and the release version
project(Monty VERSION 1.0)
# This specifies the C++ standard version we want our project to be
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# We are including the header files required
include_directories(include)
# The following specifies the name of the executable - 'HelloWorldProject'
add_executable(Monty main.cpp src/MontyHallGame.cpp)
