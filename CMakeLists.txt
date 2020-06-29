cmake_minimum_required(VERSION 3.15)
project(RegisterActivities)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)
set(SOURCE_FILES Time.h Date.h Activity.h Register.h test/runAllTests.cpp test/RegisterTestFixture.cpp test/RegisterTest.cpp)
add_executable(myexe main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(myexe core)