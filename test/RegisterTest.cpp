//
//Created by Innocenti Uccini Lisa
//

#include "lib/googletest/include/gtest/gtest.h"
#include "../Register.h"
#include <list>
#include <wx/wx.h>


TEST(RegisterTextFixture, TestAddActivity){
    Time start(4, 4, 4);
    Time stop(5, 5, 5);
    string firstDate = "06/01/20";
    string secondDate = "02/12/20";
    Activity firstEvent("title1", "fist event", start, stop);
    Activity secondEvent("title2", "second event", start, stop);
    Register *reg = new Register;
    bool added;

    added = reg->addActivity(firstDate, &firstEvent);
    added = reg->addActivity(firstDate, &firstEvent);
    added = reg->addActivity(firstDate, &secondEvent);
    added = reg->addActivity(secondDate, &firstEvent);
    added = reg->addActivity(secondDate, &secondEvent);

    list<Activity*> activities;
    activities.push_back(&firstEvent);
    activities.push_back(&secondEvent);

    ASSERT_EQ(activities, reg->getActivities(firstDate));
    ASSERT_EQ(activities, reg->getActivities(secondDate));
}

