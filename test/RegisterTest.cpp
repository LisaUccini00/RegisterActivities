#include "lib/googletest/include/gtest/gtest.h"
#include "../Register.h"
#include <list>
#include <wx/wx.h>


TEST(RegisterTextFixture, TestAddActivity){
    Time t(4, 4, 4);
    wxDateTime firstDate;
    Activity firstEvent("title1", "fist event", t, t);
    Activity secondEvent("title2", "second event", t, t);
    Register *reg = new Register;
    reg->addActivity(firstDate.Now(), firstEvent);
    reg->addActivity(firstDate, secondEvent);

    list<Activity> activities;
    activities.push_back(firstEvent);
    activities.push_back(secondEvent);
    ASSERT_EQ(activities, reg->getActivities(firstDate));


}

