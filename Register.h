
#ifndef REGISTERACTIVITIES_REGISTER_H
#define REGISTERACTIVITIES_REGISTER_H
#include <iostream>
#include <map>
#include <list>
#include <algorithm>
#include <wx/wx.h>
using namespace std;

struct Time{
    int hours, minutes, seconds;
    Time(int h, int m, int s): hours(h), minutes(m), seconds(s){}
    bool operator!=(Time uncorrect){
        if(hours != uncorrect.hours || minutes != uncorrect.minutes || seconds != uncorrect.seconds){
            return true;
        }
        return false;
    }
};

struct Activity{
    string description, title;
    Time start, stop;
    Activity(string titolo, string descrizione, Time inizio, Time fine):
            title(titolo), description(descrizione), start(inizio), stop(fine){}
    void print(){ //trasform in toString()
        cout<<title<<endl;
    }
};

class Register{
private:
    map<wxDateTime, list < Activity *>> activities;
public:
    void addActivity(wxDateTime d, Activity& a);
    void removeActivity(wxDateTime& d, Activity& a);
    list<Activity*> getActivities(const wxDateTime& d);
};
#endif //REGISTERACTIVITIES_REGISTER_H
