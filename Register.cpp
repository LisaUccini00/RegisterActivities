//
//Created by Innocenti Uccini Lisa
//

#include "Register.h"
#include <algorithm>

bool Register::addActivity(wxDateTime d, Activity& a) {
    auto day = activities.find(d);
    if(day != activities.end()){
        auto ac = find(day->second.begin(), day->second.end(), &a);
        if(ac == day->second.end()){
            day->second.push_back(&a);
            return true;
        }else{
            return false;
        }
    }else{
        list<Activity*> l;
        l.push_back(&a);
        activities.insert(make_pair(d, l));
        return true;
    }
}

void Register::removeActivity(wxDateTime &d, Activity &a) {
    auto day = activities.find(d);
    if(day != activities.end()){
        auto activity = find(day->second.begin(), day->second.end(), &a);
        if(activity != day->second.end()){
            day->second.erase(activity);
        }
    }
}

list<Activity *> Register::getActivities(const wxDateTime &d) {
    auto date = activities.find(d);
    if(date != activities.end()){
        return date->second;
    }else{
        list<Activity*> l;
        return l;
    }

}
