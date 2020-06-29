

#include "InsertFrame.h"
#include "Register.h"

InsertFrame::InsertFrame( Register& reg, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : r(&reg), wxFrame( NULL, id, title, pos, size, style )
{
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );
    this->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxT("Rubik") ) );

    wxGridSizer* firstGrid;
    firstGrid = new wxGridSizer( 5, 2, 0, 0 );

    title_static = new wxStaticText( this, wxID_ANY, wxT("Titolo attività: "), wxDefaultPosition, wxDefaultSize, 0 );
    title_static->Wrap( -1 );
    title_static->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxT("Rubik") ) );
    title_static->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
    firstGrid->Add( title_static, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
    title_text = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    title_text->SetFont( wxFont( 7, 70, 90, 90, false, wxT("Rubik") ) );
    title_text->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
    firstGrid->Add( title_text, 0, wxALL|wxEXPAND, 5 );

    description_static = new wxStaticText( this, wxID_ANY, wxT("Descrizione attività: "), wxDefaultPosition, wxDefaultSize, 0 );
    description_static->Wrap( -1 );
    description_static->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxT("Rubik") ) );
    firstGrid->Add( description_static, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
    description_text = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
    description_text->SetFont( wxFont( 7, 70, 90, 90, false, wxT("Rubik") ) );
    description_text->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
    firstGrid->Add( description_text, 0, wxALL|wxEXPAND, 5 );

    start_time_text = new wxStaticText( this, wxID_ANY, wxT("Orario inizio: "), wxDefaultPosition, wxDefaultSize, 0 );
    start_time_text->Wrap( -1 );
    start_time_text->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxT("Rubik") ) );
    start_time_text->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
    firstGrid->Add( start_time_text, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    wxGridSizer* startGrid;
    startGrid = new wxGridSizer( 1, 3, 0, 0 );

    start_hours = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 60, 0 );
    start_hours->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );
    startGrid->Add( start_hours, 0, wxALL, 5 );

    start_minutes = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 60, 0 );
    start_minutes->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );
    startGrid->Add( start_minutes, 0, wxALL, 5 );

    start_seconds = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 60, 0 );
    start_seconds->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );

    startGrid->Add( start_seconds, 0, wxALL, 5 );
    firstGrid->Add( startGrid, 1, 0, 5 );

    stop_time_text = new wxStaticText( this, wxID_ANY, wxT("Orario fine: "), wxDefaultPosition, wxDefaultSize, 0 );
    stop_time_text->Wrap( -1 );
    stop_time_text->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxT("Rubik") ) );
    stop_time_text->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
    firstGrid->Add( stop_time_text, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    wxGridSizer* stopGrid;
    stopGrid = new wxGridSizer( 1, 3, 0, 0 );

    stop_hours = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 60, 0 );
    stop_hours->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );
    stopGrid->Add( stop_hours, 0, wxALL, 5 );

    stop_minutes = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 60, 0 );
    stop_minutes->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );
    stopGrid->Add( stop_minutes, 0, wxALL, 5 );

    stop_seconds = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 60, 0 );
    stop_seconds->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );
    stopGrid->Add( stop_seconds, 0, wxALL, 5 );
    firstGrid->Add( stopGrid, 1, 0, 5 );

    date_actvity = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_DROPDOWN );
    date_actvity->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );
    date_actvity->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
    firstGrid->Add( date_actvity, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    wxGridSizer* buttonGrid;
    buttonGrid = new wxGridSizer( 2, 1, 0, 0 );
    insert_button = new wxButton( this, wxID_ANY, wxT("Aggiungi"), wxPoint( -1,-1 ), wxSize( -1,-1 ), 0 );
    insert_button->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );
    insert_button->SetForegroundColour( wxColour( 255, 128, 0 ) );
    insert_button->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
    buttonGrid->Add( insert_button, 0, wxALL|wxEXPAND, 5 );
    return_button = new wxButton( this, wxID_ANY, wxT("Home"), wxDefaultPosition, wxDefaultSize, 0 );
    return_button->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );
    return_button->SetForegroundColour( wxColour( 255, 128, 0 ) );
    return_button->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
    buttonGrid->Add( return_button, 0, wxALL|wxEXPAND|wxLEFT, 5 );
    firstGrid->Add( buttonGrid, 1, wxEXPAND, 5 );
    this->SetSizer( firstGrid );

    this->Layout();
    this->Centre( wxBOTH );

    // Connect Events
    insert_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( InsertFrame::OnInsertClick ), NULL, this );
    return_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( InsertFrame::OnReturnClick ), NULL, this );
}

InsertFrame::~InsertFrame()
{
    // Disconnect Events
    closeFrame();

}

void InsertFrame::OnReturnClick(wxCommandEvent &event) {
    returnHome();
}

void InsertFrame::OnInsertClick(wxCommandEvent &event) {
    string title = title_text->GetValue().ToStdString();
    string description = description_text->GetValue().ToStdString();
    Time start(start_hours->GetValue(), start_minutes->GetValue(), start_seconds->GetValue());
    Time stop(stop_hours->GetValue(), stop_minutes->GetValue(), stop_seconds->GetValue());
    Activity a(title, description, start, stop);
    Time controll(0, 0, 0);
    if(start != controll && stop != controll && title != "" && description != "" ) {
        r->addActivity(date_actvity->GetValue(), a);
        returnHome();
    }else{
        //schermata di errore
    }

}

void InsertFrame::closeFrame() {
    return_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( InsertFrame::OnReturnClick ), NULL, this );
    insert_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( InsertFrame::OnInsertClick ), NULL, this );

}

void InsertFrame::returnHome() {
    HomeFrame *home = new HomeFrame(*r);
    home->Show( true );
    delete this;
}
