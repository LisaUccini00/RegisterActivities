//
//Created by Innocenti Uccini Lisa
//

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
    HomeFrame *home = new HomeFrame(r);
    home->Show( true );
    return true;
}

