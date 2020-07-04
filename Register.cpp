//
//Created by Innocenti Uccini Lisa
//

#include "Register.h"
#include <algorithm>

bool Register::addActivity(string d, Activity* a) {
    auto day = activities.find(d);
    if(day != activities.end()){
        list<Activity*> l = getActivities(d);
        auto ac = find(l.begin(), l.end(), a);
        if(ac == l.end()){
            day->second.push_back(a);
            return true;
        }else{
            return false;
        }
    }else{
        list<Activity*> l;
        l.push_back(a);
        activities.insert(make_pair(d, l));
        return true;
    }
}

list<Activity *> Register::getActivities(const string &d) {
    auto date = activities.find(d);
    if(date != activities.end()){
        return date->second;
    }else{
        list<Activity*> l;
        return l;
    }

}
