//
//Created by Innocenti Uccini Lisa
//

#include "lib/googletest/include/gtest/gtest.h"
#include "../Register.h"
#include <list>
#include <wx/wx.h>


TEST(RegisterTextFixture, TestAddActivity){
    Time t(4, 4, 4);
    string date = "02/12/20";
    Activity firstEvent("title1", "fist event", t, t);
    Activity secondEvent("title2", "second event", t, t);
    Register *reg = new Register;
    bool added;
    added = reg->addActivity(date, &firstEvent);
    added = reg->addActivity(date, &firstEvent);
    added = reg->addActivity(date, &secondEvent);

    list<Activity*> activities;
    activities.push_back(&firstEvent);
    activities.push_back(&secondEvent);
    ASSERT_EQ(activities, reg->getActivities(date));
}

