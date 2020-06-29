#include <iostream>
#include "Date.h"
#include "Register.h"


int main() {
    Time t(4, 4, 4);
    Date firstDate(2, 12, 2020);
    Date secondDate(6, 1, 2021);
    Activity *firstEvent = new Activity("title1", "fist event", "red", t, t);
    Activity *secondEvent = new Activity("title2", "second event", "blu", t, t);
    Activity *thirdEvent = new Activity("title3", "second event", "blu", t, t);
    Register *reg = new Register;
    reg->addActivity(firstDate, *firstEvent);
    reg->addActivity(firstDate, *secondEvent);
    reg->removeActivity(firstDate, *firstEvent);
    reg->addActivity(secondDate, *thirdEvent);
    list<Activity*> registeredA = reg->getActivities(firstDate);

    return 0;
}
