

#include "InsertFrame.h"

InsertFrame::InsertFrame( wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( NULL, id, title, pos, size, style )
{
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );
    this->SetBackgroundColour( wxColour( 208, 208, 208 ) );

    wxGridSizer* firstGrid;
    firstGrid = new wxGridSizer( 6, 1, 0, 0 );

    title_text = new wxTextCtrl( this, wxID_ANY, wxT("inserisci il titolo dell'attività..."), wxDefaultPosition, wxDefaultSize, 0 );
    title_text->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );
    title_text->SetBackgroundColour( wxColour( 239, 239, 248 ) );

    firstGrid->Add( title_text, 0, wxALL|wxEXPAND, 5 );

    description_text = new wxTextCtrl( this, wxID_ANY, wxT("inserisci la descrizione dell'attività..."), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
    description_text->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );
    description_text->SetBackgroundColour( wxColour( 239, 239, 248 ) );

    firstGrid->Add( description_text, 0, wxALL|wxEXPAND, 5 );

    wxGridSizer* startGrid;
    startGrid = new wxGridSizer( 1, 4, 0, 0 );

    start_time_text = new wxStaticText( this, wxID_ANY, wxT("orario di inizio: "), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
    start_time_text->Wrap( -1 );
    start_time_text->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );
    start_time_text->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );

    startGrid->Add( start_time_text, 0, wxALL|wxEXPAND, 5 );

    start_hours = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 24, 0 );
    start_hours->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );

    startGrid->Add( start_hours, 0, wxALL|wxEXPAND, 5 );

    start_minutes = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 60, 0 );
    start_minutes->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );

    startGrid->Add( start_minutes, 0, wxALL|wxEXPAND, 5 );

    start_seconds = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 60, 0 );
    start_seconds->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );

    startGrid->Add( start_seconds, 0, wxALL|wxEXPAND, 5 );


    firstGrid->Add( startGrid, 1, wxEXPAND, 5 );

    wxGridSizer* stopGrid;
    stopGrid = new wxGridSizer( 1, 4, 0, 0 );

    stop_time_text = new wxStaticText( this, wxID_ANY, wxT("orario di fine: "), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
    stop_time_text->Wrap( -1 );
    stop_time_text->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );
    stop_time_text->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );

    stopGrid->Add( stop_time_text, 0, wxALL|wxEXPAND, 5 );

    stop_hours = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 24, 0 );
    stop_hours->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );

    stopGrid->Add( stop_hours, 0, wxALL|wxEXPAND, 5 );

    stop_minutes = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 60, 0 );
    stop_minutes->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );

    stopGrid->Add( stop_minutes, 0, wxALL|wxEXPAND, 5 );

    stop_seconds = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 60, 0 );
    stop_seconds->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );

    stopGrid->Add( stop_seconds, 0, wxALL|wxEXPAND, 5 );


    firstGrid->Add( stopGrid, 1, wxEXPAND, 5 );

    date_actvity = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_DROPDOWN );
    date_actvity->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );
    date_actvity->SetBackgroundColour( wxColour( 249, 242, 255 ) );

    firstGrid->Add( date_actvity, 0, wxALL|wxEXPAND, 5 );

    wxStaticBoxSizer* buttonBox;
    buttonBox = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("label") ), wxHORIZONTAL );

    return_button = new wxButton( buttonBox->GetStaticBox(), wxID_ANY, wxT("Home"), wxDefaultPosition, wxDefaultSize, 0 );
    return_button->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );
    return_button->SetBackgroundColour( wxColour( 255, 242, 249 ) );

    buttonBox->Add( return_button, 0, wxALL|wxLEFT, 5 );

    insert_button = new wxButton( buttonBox->GetStaticBox(), wxID_ANY, wxT("Inserisci attività"), wxPoint( -1,-1 ), wxSize( 1000,-1 ), 0 );
    insert_button->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );
    insert_button->SetBackgroundColour( wxColour( 255, 242, 249 ) );

    buttonBox->Add( insert_button, 0, wxALL|wxEXPAND, 5 );


    firstGrid->Add( buttonBox, 1, wxEXPAND, 5 );


    this->SetSizer( firstGrid );
    this->Layout();

    this->Centre( wxBOTH );

    // Connect Events
    return_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( InsertFrame::OnReturnClick ), NULL, this );
    insert_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( InsertFrame::OnInsertClick ), NULL, this );
}

InsertFrame::~InsertFrame()
{
    // Disconnect Events
    return_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( InsertFrame::OnReturnClick ), NULL, this );
    insert_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( InsertFrame::OnInsertClick ), NULL, this );

}

void InsertFrame::OnReturnClick(wxCommandEvent &event) {
    HomeFrame *home = new HomeFrame();
    home->Show( true );
    delete this;
}
