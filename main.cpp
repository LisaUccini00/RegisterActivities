#include <iostream>
#include <wx/wx.h>
#include <wx/wxprec.h>
#include "Register.h"
#include "HomeFrame.h"

class MyApp: public wxApp
{
private:
    Register* r;
public:
    virtual bool OnInit();
};
wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    r = new Register();
    HomeFrame *home = new HomeFrame(*r);
    home->Show( true );
    return true;
}

/*int main() {
    Time t(4, 4, 4);
    Date firstDate(2, 12, 2020);
    Date secondDate(6, 1, 2021);
    Activity *firstEvent = new Activity("title1", "fist event", "red", t, t);
    Activity *secondEvent = new Activity("title2", "second event", "blu", t, t);
    Activity *thirdEvent = new Activity("title3", "second event", "blu", t, t);
    Register *reg = new Register;
    reg->addActivity(firstDate, *firstEvent);
    reg->addActivity(firstDate, *secondEvent);
    reg->removeActivity(firstDate, *firstEvent);
    reg->addActivity(secondDate, *thirdEvent);
    list<Activity*> registeredA = reg->getActivities(firstDate);

    return 0;
}*/
