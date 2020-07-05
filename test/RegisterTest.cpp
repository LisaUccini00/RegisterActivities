//
//Created by Innocenti Uccini Lisa
//

#include "lib/googletest/include/gtest/gtest.h"
#include "../Register.h"
#include <list>


TEST(RegisterTextFixture, TestAddRemoveActivity){
    Time start(4, 4, 4);
    Time stop(5, 5, 5);
    string firstDate = "06/01/20";
    string secondDate = "02/12/20";
    Activity firstEvent("title1", "fist event", start, stop);
    Activity secondEvent("title2", "second event", start, stop);
    Register *reg = new Register;

    bool added = reg->addActivity(firstDate, firstEvent);
    ASSERT_EQ(true, added);

    added = reg->addActivity(firstDate, firstEvent);
    ASSERT_EQ(false, added);

    added = reg->addActivity(firstDate, secondEvent);
    added = reg->addActivity(secondDate, secondEvent);

    list<Activity> correct1;
    correct1.push_back(firstEvent);
    correct1.push_back(secondEvent);

    list<Activity> correct2;
    correct2.push_back(secondEvent);

    ASSERT_EQ(correct1, reg->getActivities(firstDate));
    ASSERT_EQ(correct2, reg->getActivities(secondDate));

    reg->deleteActivity(secondDate);
    correct2.remove(secondEvent);

    ASSERT_EQ(correct2, reg->getActivities(secondDate));
}

