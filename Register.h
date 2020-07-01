//
//Created by Innocenti Uccini Lisa
//

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
    bool operator!=(Time& uncorrect){
        if(hours != uncorrect.hours || minutes != uncorrect.minutes || seconds != uncorrect.seconds){
            return true;
        }
        return false;
    }
    bool operator==(Time& right){
        if(hours == right.hours && minutes == right.minutes && seconds == right.seconds){
            return true;
        }
        return false;
    }
    bool operator<(Time right) {
        if (hours < right.hours) {
            return true;
        } else if (hours == right.hours) {
            if (minutes < right.minutes) {
                return true;
            } else if (minutes == right.minutes && seconds < right.seconds) {
                return true;
            }
        }
        return false;
    }
    string toString(){
        return std::to_string(hours)+":"+std::to_string(minutes)+":"+std::to_string(seconds);
    }
};

struct Activity{
    string description, title;
    Time start, stop;
    Activity(string titolo, string descrizione, Time inizio, Time fine):
            title(titolo), description(descrizione), start(inizio), stop(fine){}
    bool operator==(Activity& right){
        if(description == right.description && title == right.title && start == right.start && stop == right.stop){
            return true;
        }
        return false;
    }
};

class Register{
private:
    map<wxDateTime, list < Activity*>> activities;
public:
    bool addActivity(wxDateTime d, Activity& a);
    void removeActivity(wxDateTime& d, Activity& a);
    list<Activity*> getActivities(const wxDateTime& d);
};
#endif //REGISTERACTIVITIES_REGISTER_H
