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
    secondBox->Add( m_calendar1, 1, 5 );

    wxStaticBoxSizer* buttonBox;
    buttonBox = new wxStaticBoxSizer( new wxStaticBox( secondBox->GetStaticBox(), wxID_ANY, wxEmptyString ), wxVERTICAL );

    insert_button = new wxButton( buttonBox->GetStaticBox(), wxID_NEW,  wxT("Inserisci attività"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
    insert_button->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );
    insert_button->SetForegroundColour(wxColor(255, 128, 0));
    buttonBox->Add( insert_button, 0, wxALL|wxEXPAND, 5 );

    view_button = new wxButton( buttonBox->GetStaticBox(), wxID_ANY, wxT("Visualizza attività"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
    view_button->SetFont( wxFont( 10, 70, 90, 90, false, wxT("Rubik") ) );
    view_button->SetForegroundColour(wxColor(255, 128, 0));
    buttonBox->Add( view_button, 0, wxALL|wxEXPAND, 5 );

    help_button = new wxButton( buttonBox->GetStaticBox(), wxID_HELP );
    view_button->SetForegroundColour(wxColor(255, 128, 0));
    buttonBox->Add( help_button, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5 );

    secondBox->Add( buttonBox, 1, 5 );
    this->SetSizer( secondBox );
    this->Layout();
    this->Centre( wxBOTH );

    // Connect Events
    view_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HomeFrame::OnViewFrame ), NULL, this );
    insert_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HomeFrame::OnInsertFrame ), NULL, this );
    help_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HomeFrame::OnHelp ), NULL, this );
}

HomeFrame::~HomeFrame()
{
    insert_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HomeFrame::OnInsertFrame ), NULL, this );
    view_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HomeFrame::OnViewFrame ), NULL, this );
}

void HomeFrame::OnInsertFrame(wxCommandEvent &event) {
    wxString datawx = m_calendar1->GetDate().Format(wxT("%d/%m/%y"), wxDateTime::CET);
    string data = datawx.ToStdString();
    InsertFrame *insertF = new InsertFrame(r, data);
    insertF->Show( true );
    delete this;

}

void HomeFrame::OnViewFrame(wxCommandEvent &event) {
    wxString datawx = m_calendar1->GetDate().Format(wxT("%d/%m/%y"), wxDateTime::CET);
    string data = datawx.ToStdString();
    auto list = r->getActivities(data);
    if(list.empty()){
        wxMessageBox(wxT("Non è stata inserita alcuna attività in questa data"), wxT("Attenzione"), wxICON_ERROR, this);
    }else{
        ViewFrame *viewF = new ViewFrame(r, list);
        viewF->Show( true );
        delete this;
    }
}

void HomeFrame::OnHelp(wxCommandEvent &event) {
    wxMessageBox(wxT("Scegli un giorno e inserisci una nuova attività oppure visualizza le attività precedentemente inserite per quella determinata giornata"), wxT("Help"), wxHELP, this);
}
