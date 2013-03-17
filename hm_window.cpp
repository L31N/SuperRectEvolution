
#include <wx/dcbuffer.h>

#include "hm_window.h"
#include "app.h"

HMWindow::HMWindow(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, wxT("SuperRect Main Menu"), pos, size, style ) {
   this->SetBackgroundColour( wxColour( 0, 0, 0 ) );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );


	bSizer5->Add( 0, 0, 1, wxEXPAND, 5 );

	lbCaption = new wxStaticText( this, wxID_ANY, wxT("SUPER RECT - EVOLUTION -- MAIN MENU"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	lbCaption->Wrap( -1 );
	lbCaption->SetFont( wxFont( 20, 70, 90, 92, false, wxT("Arial Black") ) );
	lbCaption->SetForegroundColour( wxColour( 255, 35, 0 ) );

	bSizer5->Add( lbCaption, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 15 );


	bSizer5->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer5->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );

	bSizer1->Add( bSizer5, 1, wxEXPAND, 5 );

	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 2, 1, 0, 0 );


	gSizer1->Add( 0, 0, 1, wxEXPAND, 5 );

	SettingsButton = new wxButton( this, wxID_ANY, wxT("SETTINGS"), wxDefaultPosition, wxDefaultSize, 0 );
	SettingsButton->SetFont( wxFont( 20, 70, 90, 90, false, wxEmptyString ) );
	SettingsButton->SetBackgroundColour( wxColour( 0, 255, 0 ) );

	gSizer1->Add( SettingsButton, 0, wxALIGN_CENTER|wxALL|wxSHAPED, 5 );

	QuitButton = new wxButton( this, wxID_ANY, wxT("QUIT"), wxDefaultPosition, wxDefaultSize, 0 );
	QuitButton->SetFont( wxFont( 20, 70, 90, 90, false, wxEmptyString ) );
	QuitButton->SetBackgroundColour( wxColour( 255, 128, 0 ) );

	gSizer1->Add( QuitButton, 0, wxALIGN_CENTER|wxALL|wxSHAPED, 5 );


	gSizer1->Add( 0, 0, 2, wxEXPAND, 5 );


	gSizer1->Add( 0, 0, 1, wxEXPAND, 5 );

	PlayButton = new wxButton( this, wxID_ANY, wxT("PLAY GAME"), wxDefaultPosition, wxDefaultSize, 0 );
	PlayButton->SetFont( wxFont( 20, 70, 90, 90, false, wxEmptyString ) );
	PlayButton->SetForegroundColour( wxColour( 255, 0, 0 ) );
	PlayButton->SetBackgroundColour( wxColour( 0, 3, 255 ) );

	gSizer1->Add( PlayButton, 0, wxALIGN_CENTER|wxALL|wxSHAPED, 5 );


	gSizer1->Add( 0, 0, 1, wxEXPAND, 5 );

	bSizer1->Add( gSizer1, 2, wxEXPAND, 5 );

	this->SetSizer( bSizer1 );
	this->Layout();

    /*hm_background_img.LoadFile(HM_BACKGROUND_IMG, wxBITMAP_TYPE_PNG);
	hm_background_img = hm_background_img.Scale(this->GetSize().GetWidth(), this->GetSize().GetHeight(), wxIMAGE_QUALITY_HIGH);*/

	// Connect Events
	//this->Connect( wxEVT_PAINT, wxPaintEventHandler( HMWindow::OnPaint ) );

    this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler(HMWindow::OnClose));

	SettingsButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HMWindow::OnSettingsButtonClick ), NULL, this );
	QuitButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HMWindow::OnQuitButtonClick ), NULL, this );
	PlayButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HMWindow::OnPlayButtonClick ), NULL, this );

	SettingsButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( App::OnHMWindowSettingsButtonClicked), NULL, this);
}

HMWindow::~HMWindow() {}

void HMWindow::OnPaint(wxPaintEvent& event) {
    wxBufferedPaintDC pdc(this);

    if (hm_background_img.IsOk()) {
        pdc.DrawBitmap(hm_background_img, 0, 0, false);
    }

    event.Skip();
}

void HMWindow::OnClose(wxCloseEvent& event) {
    this->GetParent()->Close();
    event.Skip();
}

void HMWindow::OnSettingsButtonClick(wxCommandEvent& event) {
    event.Skip(true);
}

void HMWindow::OnQuitButtonClick(wxCommandEvent& event) {
    this->GetParent()->Close();
}

void HMWindow::OnPlayButtonClick(wxCommandEvent& event) {
}
