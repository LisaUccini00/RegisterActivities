cmake_minimum_required(VERSION 3.15)
project(RegisterActivities)

set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets REQUIRED net gl core base xrc adv )
include(${wxWidgets_USE_FILE})

add_subdirectory(test)
set(SOURCE_FILES Date.h Register.h Register.cpp InsertFrame.cpp InsertFrame.h HomeFrame.cpp HomeFrame.h)
add_executable(myexe main.cpp)

add_library(core ${SOURCE_FILES})
target_link_libraries(myexe core ${wxWidgets_LIBRARIES})


