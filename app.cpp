
#include <wx/image.h>
#include <wx/display.h>

#include "app.h"


IMPLEMENT_APP (App);

bool App::OnInit() {

    sdata = new SetupDialog::setup_data;
    sdata->resolution = wxSize(0, 0);
    sdata->fullscreen = false;
    sdata->volume = 0;

    setup = new SetupDialog(sdata, NULL);
    wxInitAllImageHandlers();
    setup->SetIcon(wxIcon(SET_ICON_FILE_PATH, wxBITMAP_TYPE_PNG));
    int retval = setup->ShowModal();

    if (retval == 1) return false;
    else if (retval < 0) {
        wxMessageDialog merr(NULL, wxT("error occured"));
        merr.ShowModal();
        return true;
    }

    frame = new HMWindow(NULL, wxID_ANY, wxDefaultPosition, sdata->resolution);
    frame->SetIcon(wxIcon(ICON_FILE_PATH, wxBITMAP_TYPE_PNG));


    if (sdata->fullscreen) {
        frame->ShowFullScreen(true, wxFULLSCREEN_ALL);
    }
    else {
        frame->Centre();
        frame->Show(true);
    }

    return true;
}

App::~App() {
    delete setup;
    delete sdata;
    delete frame;
}

void App::OnHMWindowSettingsButtonClicked(wxCommandEvent& event) {
    //wxMessageDialog msg(NULL, wxT("Settings clicked"));
    //msg.ShowModal();
    frame->Close();
}

// `wx-config  --version=2.8 --static=yes --unicode=no --debug=yes --cflags`
// `wx-config  --version=2.8 --static=yes --unicode=no --debug=no --cflags`

//`wx-config  --version=2.8 --static=yes --unicode=yes --debug=yes --libs`
//`wx-config  --version=2.8 --static=yes --unicode=yes --debug=no --libs`
