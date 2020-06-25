
#ifndef REGISTERACTIVITIES_ACTIVITY_H
#define REGISTERACTIVITIES_ACTIVITY_H
#include "Time.h"
#include <iostream>
using namespace std;

class Activity{
private:
    string description, title, color;
    Time start, stop;
public:
    Activity(string titolo, string descrizione, string colore, Time inizio, Time fine):
            title(titolo), description(descrizione), color(colore), start(inizio), stop(fine){}
    void print(){
        cout<<title<<endl;
    }
};
#endif //REGISTERACTIVITIES_ACTIVITY_H
