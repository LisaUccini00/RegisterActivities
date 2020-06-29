//
// Created by lisauccini on 29/06/20.
//
#include "Register.h"

void Register::addActivity(Date& d, Activity& a) {
    auto day = activities.find(d);
    if(day != activities.end()){
        day->second.push_back(&a);
    }else{
        list<Activity*> l;
        l.push_back(&a);
        activities.insert(make_pair(d, l));
    }
}

void Register::removeActivity(Date &d, Activity &a) {
    auto day = activities.find(d);
    if(day != activities.end()){
        auto activity = find(day->second.begin(), day->second.end(), &a);
        if(activity != day->second.end()){
            day->second.erase(activity);
        }
    }
}

list<Activity *> Register::getActivities(const Date &d) {
    cout<<"Attivita' data "<<d.getDay()<<"/"<<d.getMonth()<<"/"<<d.getYear()<<endl;
    auto date = activities.find(d);
    for(auto activity: date->second){
        activity->print();
    }
    return date->second;

}
