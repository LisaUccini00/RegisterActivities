add_subdirectory(./lib/googletest-master/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest-master/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_FILES runAllTests.cpp, RegisterTest.cpp, RegisterTestFixture.cpp)
add_executable(renRegisterTests ${SOURCE_FILES})
target_link_libraries(runRegisterTests ${GTEST_BOTH_LIBRARIES} core)