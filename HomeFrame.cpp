

#include "HomeFrame.h"
HomeFrame::HomeFrame(wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( NULL, id, title, pos, size, style )
{
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );
    this->SetBackgroundColour( wxColour( 208, 208, 208 ) );

    wxStaticBoxSizer* firstBox;
    firstBox = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("label") ), wxVERTICAL );

    insert_button = new wxButton( firstBox->GetStaticBox(), wxID_ANY, wxT("Inserisci attività"), wxDefaultPosition, wxSize( -1,-1), 0 );
    insert_button->SetFont( wxFont( 15, 70, 90, 90, false, wxT("Rubik") ) );
    insert_button->SetBackgroundColour( wxColour( 250, 239, 249 ) );

    firstBox->Add( insert_button, 0, wxALL|wxEXPAND, 5 );

    wxStaticBoxSizer* secondBox;
    secondBox = new wxStaticBoxSizer( new wxStaticBox( firstBox->GetStaticBox(), wxID_ANY, wxT("label") ), wxHORIZONTAL );

    m_calendar1 = new wxCalendarCtrl( secondBox->GetStaticBox(), wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxCAL_SHOW_HOLIDAYS );
    secondBox->Add( m_calendar1, 0, wxALL, 5 );

    view_button = new wxButton( secondBox->GetStaticBox(), wxID_ANY, wxT("Visualizza attività"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
    view_button->SetFont( wxFont( 15, 70, 90, 90, false, wxT("Rubik") ) );
    view_button->SetBackgroundColour( wxColour( 238, 238, 255 ) );

    secondBox->Add( view_button, 0, wxALL|wxEXPAND, 5 );


    firstBox->Add( secondBox, 1, wxEXPAND, 5 );


    this->SetSizer( firstBox );
    this->Layout();

    this->Centre( wxBOTH );

    // Connect Events
    insert_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HomeFrame::OnInsertFrame ), NULL, this );
    view_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HomeFrame::OnViewFrame ), NULL, this );
}

HomeFrame::~HomeFrame()
{
    // Disconnect Events
    insert_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HomeFrame::OnInsertFrame ), NULL, this );
    view_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HomeFrame::OnViewFrame ), NULL, this );

}

void HomeFrame::OnInsertFrame(wxCommandEvent &event) {
    InsertFrame *insertF = new InsertFrame();
    insertF->Show( true );
    delete this;
}
