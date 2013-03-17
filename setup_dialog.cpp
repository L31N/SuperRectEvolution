
#include "setup_dialog.h"

#include "wx/display.h"


SetupDialog::SetupDialog(setup_data* sdata, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style ) {
    setupdata = sdata;

    this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer0;
	bSizer0 = new wxBoxSizer( wxVERTICAL );

	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer0->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );

	lbResolution2 = new wxStaticText( this, wxID_ANY, wxT("------- Resolution -------"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	lbResolution2->Wrap( -1 );
	lbResolution2->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, true, wxT("Comic Sans MS") ) );

	bSizer0->Add( lbResolution2, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

    /// try to analyse the right resolution for screen and set it as default
    unsigned int resX = wxDisplay(0).GetGeometry().GetSize().GetWidth();
    unsigned int resY = wxDisplay(0).GetGeometry().GetSize().GetHeight();
    short stdChoice = -1;

    if (wxSize(resX, resY) == wxSize(1920, 1200)) {
        stdChoice = 0;
    }
    else if (wxSize(resX, resY) == wxSize(1920, 1080)) {
        stdChoice = 1;
    }
    else if (wxSize(resX, resY) == wxSize(1680, 1050)) {
        stdChoice = 2;
    }
    else if (wxSize(resX, resY) == wxSize(1680, 900)) {
        stdChoice = 3;
    }
    else if (wxSize(resX, resY) == wxSize(1440, 900)) {
        stdChoice = 4;
    }
    else if (wxSize(resX, resY) == wxSize(1400, 1050)) {
        stdChoice = 5;
    }
    else if (wxSize(resX, resY) == wxSize(1280, 1024)) {
        stdChoice = 6;
    }
    else if (wxSize(resX, resY) == wxSize(1280, 800)) {
        stdChoice = 7;
    }
    else if (wxSize(resX, resY) == wxSize(1280, 768)) {
        stdChoice = 8;
    }
    else if (wxSize(resX, resY) == wxSize(1024, 768)) {
        stdChoice = 9;
    }
    else {  // nothing found set the resolution to 800x600
        stdChoice = 10;
    }


	wxString ResolutionChoiceChoices[] = { wxT("1920x1200"), wxT("1920x1080"), wxT("1680x1050"), wxT("1600x900"), wxT("1440x900"), wxT("1400x1050"), wxT("1280x1024"), wxT("1280x800"), wxT("1280x768"), wxT("1024x768"), wxT("800x600") };
	int ResolutionChoiceNChoices = sizeof( ResolutionChoiceChoices ) / sizeof( wxString );
	ResolutionChoice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, ResolutionChoiceNChoices, ResolutionChoiceChoices, 0 );
	ResolutionChoice->SetSelection( stdChoice );
	ResolutionChoice->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxT("Comic Sans MS") ) );

	bSizer0->Add( ResolutionChoice, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxSHAPED, 5 );


	bSizer0->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticline3 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer0->Add( m_staticline3, 0, wxEXPAND | wxALL, 5 );

	lbSound = new wxStaticText( this, wxID_ANY, wxT("------- Volume -------"), wxDefaultPosition, wxDefaultSize, 0 );
	lbSound->Wrap( -1 );
	lbSound->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxT("Comic Sans MS") ) );

	bSizer0->Add( lbSound, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	SoundSlider = new wxSlider( this, wxID_ANY, 60, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
	SoundSlider->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxT("Droid Sans") ) );

	bSizer0->Add( SoundSlider, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5 );

	m_staticline4 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer0->Add( m_staticline4, 0, wxEXPAND | wxALL, 5 );

	FullscreenCheck = new wxCheckBox( this, wxID_ANY, wxT("Play in fullscreen"), wxDefaultPosition, wxDefaultSize, 0 );
	FullscreenCheck->SetValue(true);
	bSizer0->Add( FullscreenCheck, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer0->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );


	bSizer0->Add( 0, 0, 0, wxEXPAND, 5 );

	ButtonSizer = new wxStdDialogButtonSizer();
	ButtonSizerOK = new wxButton( this, wxID_OK );
	ButtonSizer->AddButton( ButtonSizerOK );
	ButtonSizerCancel = new wxButton( this, wxID_CANCEL );
	ButtonSizer->AddButton( ButtonSizerCancel );
	ButtonSizer->Realize();
	bSizer0->Add( ButtonSizer, 3, wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5 );

	this->SetSizer( bSizer0 );
	this->Layout();

	// Connect Events
	ButtonSizerCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetupDialog::OnCancelButtonClick ), NULL, this );
	ButtonSizerOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetupDialog::OnOKButtonClick ), NULL, this );

	Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(SetupDialog::OnClose));
}

SetupDialog::~SetupDialog() {
}

void SetupDialog::OnCancelButtonClick(wxCommandEvent& event) {
    this->EndModal(1);
}

void SetupDialog::OnOKButtonClick(wxCommandEvent& event) {

    /// extract the resolution
    if (ResolutionChoice->GetSelection() == 0) setupdata->resolution = wxSize(1920, 1200);
    else if (ResolutionChoice->GetSelection() == 1) setupdata->resolution = wxSize(1920, 1080);
    else if (ResolutionChoice->GetSelection() == 2) setupdata->resolution = wxSize(1680, 1050);
    else if (ResolutionChoice->GetSelection() == 3) setupdata->resolution = wxSize(1680, 900);
    else if (ResolutionChoice->GetSelection() == 4) setupdata->resolution = wxSize(1440, 900);
    else if (ResolutionChoice->GetSelection() == 5) setupdata->resolution = wxSize(1400, 1050);
    else if (ResolutionChoice->GetSelection() == 6) setupdata->resolution = wxSize(1280, 1024);
    else if (ResolutionChoice->GetSelection() == 7) setupdata->resolution = wxSize(1280, 800);
    else if (ResolutionChoice->GetSelection() == 8) setupdata->resolution = wxSize(1280, 768);
    else if (ResolutionChoice->GetSelection() == 9) setupdata->resolution = wxSize(1024, 768);
    else if (ResolutionChoice->GetSelection() == 10) setupdata->resolution = wxSize(800, 600);
    else {
        wxMessageDialog reserror(this, wxT("sorry the resolution is not available"));
        reserror.ShowModal();

        return;
    }

    setupdata->fullscreen = FullscreenCheck->GetValue();
    setupdata->volume = SoundSlider->GetValue();

    this->Close();
}

void SetupDialog::OnClose(wxCloseEvent& event) {
    this->EndModal(0);
    event.Skip();
}
