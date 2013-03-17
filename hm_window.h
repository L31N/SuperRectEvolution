
#ifndef _HM_WINDOW_H_
#define _HM_WINDOW_H_

#include <wx/wx.h>

#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/panel.h>

class HMWindow : public wxDialog {
    public:
        HMWindow(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER) );
        ~HMWindow();

    protected:

		wxStaticText* lbCaption;

		wxStaticLine* m_staticline1;

		wxButton* SettingsButton;
		wxButton* QuitButton;


		wxButton* PlayButton;



        /** other resources **/
        wxImage hm_background_img;


		// event handle methods
		virtual void OnPaint( wxPaintEvent& event );
		virtual void OnClose( wxCloseEvent& event );

		virtual void OnSettingsButtonClick( wxCommandEvent& event );
		virtual void OnQuitButtonClick( wxCommandEvent& event );
		virtual void OnPlayButtonClick( wxCommandEvent& event );
};

const wxString HM_BACKGROUND_IMG (wxT("resources/titlescreen640480_v2.png"));

#endif // _HM_WINDOW_H_
