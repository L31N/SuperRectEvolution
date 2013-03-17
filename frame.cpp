
#include "frame.h"

MainFrame::MainFrame(wxWindow* parent, wxSize size) : wxFrame(parent, 0, wxT("*** SuperRect - Evolution ***"), wxDefaultPosition, size, wxDEFAULT_FRAME_STYLE, wxT("main_frame")) {

    resolutionX = 0;
    resolutionY = 0;
    fullscreen = false;

    wxInitAllImageHandlers();
    this->SetIcon(wxIcon(ICON_FILE_PATH, wxBITMAP_TYPE_PNG));

    hm = new HMWindow(this);
    hm->Show(true);
}

MainFrame::~MainFrame() {
}

void MainFrame::OnClose(wxCloseEvent& event) {
    wxMessageDialog md(this, wxT("MainFrame::OnClose()"));
    md.ShowModal();
}
