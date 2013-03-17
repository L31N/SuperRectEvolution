
#ifndef _APP_H_
#define _APP_H_

#include <wx/wx.h>

#include "frame.h"
#include "setup_dialog.h"
#include "hm_window.h"

class App : public wxApp {
    public:
        bool OnInit();

        ~App();

        virtual void OnHMWindowSettingsButtonClicked(wxCommandEvent& event);

    private:
        HMWindow* frame;

        SetupDialog::setup_data* sdata;
        SetupDialog* setup;
};

/** CONSTANTS **/

#endif // _APP_H_
