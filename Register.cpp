//
//Created by Innocenti Uccini Lisa
//

#include "Register.h"
#include <algorithm>

bool Register::addActivity(string d, Activity& a) {
    auto day = activities.find(d);
    if(day != activities.end()){
        list<Activity> l = day->second;
        auto findAct = find(l.begin(), l.end(), a);
        if(findAct == l.end()){
            day->second.push_back(a);
            return true;
        }else{
            return false;
        }
    }else{
        list<Activity> l;
        l.push_back(a);
        activities.insert(make_pair(d, l));
        return true;
    }
}

list<Activity> Register::getActivities(const string &d){
    auto date = activities.find(d);
    list<Activity> l;
    if(date != activities.end()) {
        l = date->second;
    }
    return l;

}

void Register::deleteActivity(const string d) {
    activities.erase(d);
}

