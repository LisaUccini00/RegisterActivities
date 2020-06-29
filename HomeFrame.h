

#ifndef REGISTERACTIVITIES_HOMEFRAME_H
#define REGISTERACTIVITIES_HOMEFRAME_H
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/calctrl.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/frame.h>
#include "InsertFrame.h"
class HomeFrame : public wxFrame
{
private:

protected:
    wxButton* insert_button;
    wxCalendarCtrl* m_calendar1;
    wxButton* view_button;

public:

    HomeFrame( wxWindowID id = wxID_ANY, const wxString& title = wxT("Home"), const wxPoint& pos = wxPoint(50, 50), const wxSize& size = wxSize( 855, 489 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

    ~HomeFrame();

    // Virtual event handlers, overide them in your derived class
    virtual void OnInsertFrame( wxCommandEvent& event );
    virtual void OnViewFrame( wxCommandEvent& event ) { event.Skip(); }

};
#endif //REGISTERACTIVITIES_HOMEFRAME_H
