# CMakeLists.txt for fishing problem

cmake_minimum_required(VERSION 3.10)

# Project name
project(fishing LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(code src/main.cpp)
