
#ifndef _SETUP_DIALOG_H_
#define _SETUP_DIALOG_H_

#include <wx/wx.h>

#include <wx/statline.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/slider.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>

class SetupDialog : public wxDialog {
    public:

        struct setup_data {
            wxSize resolution;
            bool fullscreen;
            unsigned short volume;
        };

        SetupDialog(setup_data* sdata, wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("# SuperRect Evolution | Settings #"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 303,372 ), long style = wxDEFAULT_DIALOG_STYLE);
        ~SetupDialog();

    protected:
        wxStaticLine* m_staticline2;
		wxStaticText* lbResolution2;
		wxChoice* ResolutionChoice;

		wxStaticLine* m_staticline3;
		wxStaticText* lbSound;
		wxSlider* SoundSlider;
		wxStaticLine* m_staticline4;
		wxCheckBox* FullscreenCheck;
		wxStaticLine* m_staticline1;

		wxStdDialogButtonSizer* ButtonSizer;
		wxButton* ButtonSizerOK;
		wxButton* ButtonSizerCancel;

		unsigned int resolutionX;
        unsigned int resolutionY;

        virtual void OnCancelButtonClick( wxCommandEvent& event );
		virtual void OnOKButtonClick( wxCommandEvent& event );

        virtual void OnClose( wxCloseEvent& event );

    private:
        setup_data* setupdata;
};

#endif // _SETUP_DIALOG_H_
