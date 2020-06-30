//
//Created by Innocenti Uccini Lisa
//

#include "HomeFrame.h"
#include "ViewFrame.h"
#include <list>
HomeFrame::HomeFrame(Register* reg, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : r(reg), wxFrame( NULL, id, title, pos, size, style )
{
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );
    this->SetBackgroundColour( wxColour( 208, 208, 208 ) );

    wxStaticBoxSizer* secondBox;
    secondBox = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY , wxEmptyString), wxHORIZONTAL );

    m_calendar1 = new wxCalendarCtrl( secondBox->GetStaticBox(), wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxSize( -1,-1 ), wxCAL_SHOW_HOLIDAYS );
    secondBox->Add( m_calendar1, 0, wxALL, 5 );

    wxStaticBoxSizer* buttonBox;
    buttonBox = new wxStaticBoxSizer( new wxStaticBox( secondBox->GetStaticBox(), wxID_ANY, wxEmptyString ), wxVERTICAL );

    insert_button = new wxButton( buttonBox->GetStaticBox(), wxID_ANY, wxT("Inserisci attività"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
    insert_button->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );
    insert_button->SetForegroundColour(wxColor(255, 128, 0));
    buttonBox->Add( insert_button, 0, wxALL|wxEXPAND, 5 );

    view_button = new wxButton( buttonBox->GetStaticBox(), wxID_ANY, wxT("Visualizza attività"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
    view_button->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );
    view_button->SetForegroundColour(wxColor(255, 128, 0));
    buttonBox->Add( view_button, 0, wxALL|wxEXPAND, 5 );

    close_button = new wxButton( buttonBox->GetStaticBox(), wxID_ANY, wxT("Chiudi"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
    close_button->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );
    close_button->SetForegroundColour(wxColor(255, 128, 0));
    buttonBox->Add( close_button, 0, wxALL|wxEXPAND, 5 );

    wxButton * help_button = new wxButton( buttonBox->GetStaticBox(), wxID_HELP );
    /*help_button->SetFont( wxFont( 7, 70, 90, 90, false, wxT("Rubik") ) );
    help_button->SetForegroundColour(wxColor(255, 128, 0));*/
    buttonBox->Add( help_button, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5 );


    secondBox->Add( buttonBox, 1, 5 );
    this->SetSizer( secondBox );
    this->Layout();

    this->Centre( wxBOTH );

    // Connect Events
    view_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HomeFrame::OnViewFrame ), NULL, this );
    insert_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HomeFrame::OnInsertFrame ), NULL, this );
    close_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HomeFrame::closeFrame ), NULL, this );
    help_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HomeFrame::OnHelp ), NULL, this );
}

HomeFrame::~HomeFrame()
{
    insert_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HomeFrame::OnInsertFrame ), NULL, this );
    view_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HomeFrame::OnViewFrame ), NULL, this );
}

void HomeFrame::OnInsertFrame(wxCommandEvent &event) {

    InsertFrame *insertF = new InsertFrame(*r);
    insertF->Show( true );
    delete this;

}

void HomeFrame::closeFrame( wxCommandEvent& event ){
    insert_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HomeFrame::OnInsertFrame ), NULL, this );
    view_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HomeFrame::OnViewFrame ), NULL, this );
    delete this;
}

void HomeFrame::OnViewFrame(wxCommandEvent &event) {
    auto list = r->getActivities(m_calendar1->GetDate());
    for(auto it: list){
        cout<<it->title<<endl;
    }
    wxString data = m_calendar1->GetDate().Format(wxT("%d/%m/%y"), wxDateTime::CET);
    if(list.empty()){
        wxMessageBox(wxT("Non è stata inserita alcuna attività in questa data"), wxT("Attenzione"), wxICON_ERROR, this);
    }else{
        ViewFrame *viewF = new ViewFrame(r, list, data);
        viewF->Show( true );
        delete this;
    }

    //prendi la data, se c'è almeno una attività allora viewFrame altrimenti finestra di errore
}

void HomeFrame::OnHelp(wxCommandEvent &event) {
    wxMessageBox(wxT("Inserisci una nuova attività oppure scegli una data e visualizza le attività effettuate quel giorno"), wxT("Help"), wxHELP, this);
}
