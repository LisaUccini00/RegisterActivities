#include "lib/googletest-master/googletest/include/gtest/gtest.h"
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