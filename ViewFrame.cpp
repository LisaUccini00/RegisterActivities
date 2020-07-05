//
//Created by Innocenti Uccini Lisa
//

#include "ViewFrame.h"
#include "HomeFrame.h"
#include "Register.h"
#include <list>

ViewFrame::ViewFrame( Register* reg, list<Activity*> a, const wxString& title, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : r(reg), listActivity(a), wxFrame( NULL, id, title, pos, size, style )
{
    int number = a.size();

    this->SetSizeHints( wxDefaultSize, wxDefaultSize );

    wxStaticBoxSizer* generalBox;
    generalBox = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxEmptyString ), wxVERTICAL );
    wxGridSizer* grid;
    grid = new wxGridSizer( number+1, 4, 0, 0 );

    title_static1 = new wxStaticText( generalBox->GetStaticBox(), wxID_ANY, wxT("Titolo"), wxDefaultPosition, wxDefaultSize, 0 );
    title_static1->Wrap( -1 );
    title_static1->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxT("Rubik") ) );
    title_static1->SetForegroundColour( wxColour(255, 128, 0));
    grid->Add( title_static1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    description_static1 = new wxStaticText( generalBox->GetStaticBox(), wxID_ANY, wxT("Descrizione"), wxDefaultPosition, wxDefaultSize, 0 );
    description_static1->Wrap( -1 );
    description_static1->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxT("Rubik") ) );
    description_static1->SetForegroundColour( wxColour(255, 128, 0));
    grid->Add( description_static1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    start_static = new wxStaticText( generalBox->GetStaticBox(), wxID_ANY, wxT("Inizio"), wxDefaultPosition, wxDefaultSize, 0 );
    start_static->Wrap( -1 );
    start_static->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxT("Rubik") ) );
    start_static->SetForegroundColour( wxColour(255, 128, 0));
    grid->Add( start_static, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    stop_static = new wxStaticText( generalBox->GetStaticBox(), wxID_ANY, wxT("Fine"), wxDefaultPosition, wxDefaultSize, 0 );
    stop_static->Wrap( -1 );
    stop_static->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxT("Rubik") ) );
    stop_static->SetForegroundColour( wxColour(255, 128, 0));
    grid->Add( stop_static, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    for(auto activity: listActivity){
        wxString titolo(activity->title.c_str(), wxConvUTF8);
        wxString descrizione(activity->description.c_str(), wxConvUTF8);
        wxString start(activity->start.toString().c_str(), wxConvUTF8);
        wxString stop(activity->stop.toString().c_str(), wxConvUTF8);

        title_text = new wxTextCtrl( this, wxID_ANY, titolo, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY );
        title_text->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxT("Rubik") ) );
        title_text->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
        grid->Add( title_text, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

        description_text = new wxTextCtrl( this, wxID_ANY, descrizione, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY );
        description_text->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxT("Rubik") ) );
        description_text->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
        grid->Add( description_text, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

        start_static = new wxStaticText( generalBox->GetStaticBox(), wxID_ANY, start, wxDefaultPosition, wxDefaultSize, 0 );
        start_static->Wrap( -1 );
        start_static->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxT("Rubik") ) );
        grid->Add( start_static, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

        stop_static = new wxStaticText( generalBox->GetStaticBox(), wxID_ANY, stop, wxDefaultPosition, wxDefaultSize, 0 );
        stop_static->Wrap( -1 );
        stop_static->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxT("Rubik") ) );
        grid->Add( stop_static, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
    }

    generalBox->Add( grid, 1, 5 );

    return_button = new wxButton( generalBox->GetStaticBox(), wxID_ANY, wxT("Home"), wxDefaultPosition, wxDefaultSize, 0 );
    return_button->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );
    return_button->SetForegroundColour( wxColour( 255, 128, 0 ) );
    return_button->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
    generalBox->Add( return_button, 0, wxALL|wxEXPAND|wxLEFT, 5 );

    this->SetSizer( generalBox );
    this->Layout();
    this->Centre( wxBOTH );

    // Connect Events
    return_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ViewFrame::OnReturnClick ), NULL, this );
}

ViewFrame::~ViewFrame()
{
    // Disconnect Events
    return_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ViewFrame::OnReturnClick ), NULL, this );
}

void ViewFrame::OnReturnClick(wxCommandEvent &event) {
    HomeFrame *home = new HomeFrame(r);
    home->Show( true );
    delete this;
}
