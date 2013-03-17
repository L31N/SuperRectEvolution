
#ifndef _FRAME_H_
#define _FRAME_H_

#include <wx/wx.h>

#include "hm_window.h"

class MainFrame : public wxFrame {
    public:
        MainFrame(wxWindow* parent, wxSize size);
        ~MainFrame();

    protected:
        virtual void OnClose(wxCloseEvent& event);

    private:
        unsigned int resolutionX;
        unsigned int resolutionY;
        bool fullscreen;

        HMWindow* hm;
};

const wxString ICON_FILE_PATH (wxT("resources/sreicon.png"));
const wxString SET_ICON_FILE_PATH (wxT("resources/sreseticon.png"));


#endif // _FRAME_H_
