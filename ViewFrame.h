//
//Created by Innocenti Uccini Lisa
//

#ifndef REGISTERACTIVITIES_VIEWFRAME_H
#define REGISTERACTIVITIES_VIEWFRAME_H
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/statbox.h>
#include <wx/frame.h>
#include <wx/wx.h>
#include "Register.h"

class ViewFrame : public wxFrame
{
private:
    Register *r;
    list<Activity*> listActivity;
protected:
    wxStaticText* title_static1;
    wxStaticText* description_static1;
    wxStaticText* start_static;
    wxStaticText* stop_static;
    wxTextCtrl* title_text;
    wxTextCtrl* description_text;
    wxButton* return_button;

    // Virtual event handlers, overide them in your derived class
    virtual void OnReturnClick( wxCommandEvent& event );

public:

    ViewFrame( Register* reg, list<Activity*> a, const wxString& title = wxT("Visualizza attività"), wxWindowID id = wxID_ANY,  const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
    ~ViewFrame();
};
#endif //REGISTERACTIVITIES_VIEWFRAME_H
