#include "lib/googletest/include/gtest/gtest.h"
#include "../Register.h"
#include "../Date.h"
#include <list>



TEST(RegisterTextFixture, TestAddRemoveActivity){
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
    ASSERT_EQ(activities, reg->getActivities(firstDate));

    reg->removeActivity(firstDate, *firstEvent);

    list<Activity*> activities1;
    activities1.push_back(secondEvent);

    ASSERT_EQ(activities1, reg->getActivities(firstDate));
}

