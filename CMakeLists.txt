cmake_minimum_required(VERSION 3.15)
project(RegisterActivities)

set(CMAKE_CXX_STANDARD 14)

add_executable(RegisterActivities main.cpp Time.h Date.h Activity.h Register.h test/runAllTests.cpp)

add_subdirectory(test)
set(SOURCE_FILES test/RegisterTestFixture.cpp test/RegisterTest.cpp)
add_executable(test main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(test core)