
#ifndef REGISTERACTIVITIES_REGISTER_H
#define REGISTERACTIVITIES_REGISTER_H
#include "Date.h"
#include <iostream>
#include <map>
#include <list>
#include <algorithm>
using namespace std;

struct Time{
    int hours, minutes, seconds;
    Time(int h, int m, int s): hours(h), minutes(m), seconds(s){}
};

struct Activity{
    string description, title, color;
    Time start, stop;
    Activity(string titolo, string descrizione, string colore, Time inizio, Time fine):
            title(titolo), description(descrizione), color(colore), start(inizio), stop(fine){}
    void print(){ //trasform in toString()
        cout<<title<<endl;
    }
};

class Register{
private:
    map<Date, list < Activity *>> activities;
public:
    void addActivity(Date& d, Activity& a);
    void removeActivity(Date& d, Activity& a);
    list<Activity*> getActivities(const Date& d);
};
#endif //REGISTERACTIVITIES_REGISTER_H
