#include "lib/googletest/include/gtest/gtest.h"
#include "../Register.h"
#include "../Activity.h"
#include "../Date.h"
#include "../Time.h"
#include <map>
#include <list>

TEST(Register, TestAddRemoveActivity){
    Time t(4, 4, 4);
    Date firstDate(2, 12, 2020);
    Activity *firstEvent = new Activity("title1", "fist event", "red", t, t);
    Activity *secondEvent = new Activity("title2", "second event", "blu", t, t);
    Register *reg = new Register;
    reg->addActivity(firstDate, *firstEvent);
    reg->addActivity(firstDate, *secondEvent);

    list<Activity*> activities;
    activities.push_back(firstEvent);
    activities.push_back(secondEvent);
    map<Date, list<Activity*>> correctRegAdd;
    correctRegAdd.insert(make_pair(firstDate, activities));
    ASSERT_EQ(correctRegAdd, reg->getMap());

    reg->removeActivity(firstDate, *firstEvent);

    list<Activity*> activities1;
    activities.push_back(secondEvent);
    map<Date, list<Activity*>> correctRegRem;
    correctRegRem.insert(make_pair(firstDate, activities1));

    ASSERT_EQ(correctRegRem, reg->getMap());
}

/*
 * add_subdirectory(googletest)
set(gtest_SOURCE_DIR, googletest)
cmake_minimum_required(VERSION 3.5)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCE_FILES RegisterTest.cpp, RegisterTestFixture.cpp)
add_executable(test runAllTests.cpp)
add_library(testcore ${SOURCE_FILES})
target_link_libraries(test ${GTEST_BOTH_LIBRARIES} testcore)
 */