
#ifndef REGISTERACTIVITIES_REGISTER_H
#define REGISTERACTIVITIES_REGISTER_H
#include "Activity.h"
#include "Date.h"
#include <iostream>
#include <map>
#include <list>
#include <algorithm>
using namespace std;

class Register{
private:
    map<Date, list < Activity *>> activities;
public:
    void addActivity(Date& d, Activity& a) {
        auto day = activities.find(d);
        if(day != activities.end()){
            day->second.push_back(&a);
        }else{
            list<Activity*> l;
            l.push_back(&a);
            activities.insert(make_pair(d, l));
        }
    }
    void removeActivity(Date& d, Activity& a){
        auto day = activities.find(d);
        if(day != activities.end()){
            auto activity = find(day->second.begin(), day->second.end(), &a);
            if(activity != day->second.end()){
                day->second.erase(activity);
            }
        }
    }
    void getActivities(const Date& d){
        cout<<"Attivita' data "<<d.getDay()<<"/"<<d.getMonth()<<"/"<<d.getYear()<<endl;
        auto date = activities.find(d);
        for(auto activity: date->second){
            activity->print();
        }

    }
    map<Date, list < Activity *>> getMap(){
        return activities;
    }
    bool operator==(const Register& right){
        for (auto day: activities){
            for(auto activity: day.second){
            }
        }
    }
};
#endif //REGISTERACTIVITIES_REGISTER_H
