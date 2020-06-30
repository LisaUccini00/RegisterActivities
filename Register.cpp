//
//Created by Innocenti Uccini Lisa
//

#include "Register.h"

void Register::addActivity(wxDateTime d, Activity& a) {
    auto day = activities.find(d);
    if(day != activities.end()){
        day->second.push_back(&a);
    }else{
        list<Activity*> l;
        l.push_back(&a);
        activities.insert(make_pair(d, l));
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
        for(auto it: date->second){
            cout<<it->title<<endl;
        }
        return date->second;
    }else{
        list<Activity*> l;
        return l;
    }

}
