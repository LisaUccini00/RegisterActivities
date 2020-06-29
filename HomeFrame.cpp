

#include "HomeFrame.h"
HomeFrame::HomeFrame(Register& reg, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : r(&reg), wxFrame( NULL, id, title, pos, size, style )
{
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );
    this->SetBackgroundColour( wxColour( 208, 208, 208 ) );

    wxStaticBoxSizer* secondBox;
    secondBox = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY , wxEmptyString), wxHORIZONTAL );

    m_calendar1 = new wxCalendarCtrl( secondBox->GetStaticBox(), wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxSize( -1,-1 ), wxCAL_SHOW_HOLIDAYS );
    secondBox->Add( m_calendar1, 0, wxALL, 5 );

    wxStaticBoxSizer* buttonBox;
    buttonBox = new wxStaticBoxSizer( new wxStaticBox( secondBox->GetStaticBox(), wxID_ANY, wxEmptyString ), wxVERTICAL );

    view_button = new wxButton( buttonBox->GetStaticBox(), wxID_ANY, wxT("Visualizza attività"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
    view_button->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );
    view_button->SetForegroundColour(wxColor(255, 128, 0));
    buttonBox->Add( view_button, 0, wxALL|wxEXPAND, 5 );

    insert_button = new wxButton( buttonBox->GetStaticBox(), wxID_ANY, wxT("Inserisci attività"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
    insert_button->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );
    insert_button->SetForegroundColour(wxColor(255, 128, 0));
    buttonBox->Add( insert_button, 0, wxALL|wxEXPAND, 5 );

    secondBox->Add( buttonBox, 1, 5 );
    this->SetSizer( secondBox );
    this->Layout();

    this->Centre( wxBOTH );

    // Connect Events
    view_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HomeFrame::OnViewFrame ), NULL, this );
    insert_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HomeFrame::OnInsertFrame ), NULL, this );
}

HomeFrame::~HomeFrame()
{
    closeFrame();
}

void HomeFrame::OnInsertFrame(wxCommandEvent &event) {

    InsertFrame *insertF = new InsertFrame(*r);
    insertF->Show( true );
    delete this;

}

void HomeFrame::closeFrame(){
    insert_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HomeFrame::OnInsertFrame ), NULL, this );
    view_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HomeFrame::OnViewFrame ), NULL, this );
}