cmake_minimum_required(VERSION 3.10)
# Name of the project and the release version

project(project VERSION 1.0)
# This specifies the C++ standard version we want our project to be in
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# We are including the header files required
include_directories(include)
# The following specifies the name of the executable
add_executable(project main.cpp src/hello_world.cpp)
# Added the following lines for integrating tests
add_executable(Test tests/tests.cpp src/str.cpp)
enable_testing()
add_test(NAME Test COMMAND Test)