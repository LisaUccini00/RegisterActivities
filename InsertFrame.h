
#ifndef REGISTERACTIVITIES_INSERTFRAME_H
#define REGISTERACTIVITIES_INSERTFRAME_H

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/spinctrl.h>
#include <wx/sizer.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/button.h>
#include <wx/statbox.h>
#include <wx/frame.h>

#include "HomeFrame.h"


class InsertFrame : public wxFrame
{
private:

protected:
    wxTextCtrl* title_text;
    wxTextCtrl* description_text;
    wxStaticText* start_time_text;
    wxSpinCtrl* start_hours;
    wxSpinCtrl* start_minutes;
    wxSpinCtrl* start_seconds;
    wxStaticText* stop_time_text;
    wxSpinCtrl* stop_hours;
    wxSpinCtrl* stop_minutes;
    wxSpinCtrl* stop_seconds;
    wxDatePickerCtrl* date_actvity;
    wxButton* return_button;
    wxButton* insert_button;

    // Virtual event handlers, overide them in your derived class
    virtual void OnReturnClick( wxCommandEvent& event );
    virtual void OnInsertClick( wxCommandEvent& event ) { event.Skip(); }


public:

    InsertFrame( wxWindowID id = wxID_ANY, const wxString& title = wxT("insert activity"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1211,667 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

    ~InsertFrame();

};

#endif //REGISTERACTIVITIES_INSERTFRAME_H
