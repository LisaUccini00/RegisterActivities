cmake_minimum_required(VERSION 3.15)
project(RegisterActivities)

set(CMAKE_CXX_STANDARD 14)

add_executable(RegisterActivities main.cpp Time.h Date.h Activity.h Register.h)