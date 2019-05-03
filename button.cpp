#include <wx/wx.h>
#include <wx/listbox.h>
#include <wx/msgdlg.h>
class MyPanel : public wxPanel
{
public:
	MyPanel(wxPanel *parent);
	void OnNew(wxCommandEvent& event);
	void OnLoad(wxCommandEvent& event);
	wxListBox *m_lb;
	wxButton *m_newb;
	wxButton *m_loadb;
  wxButton *m_exitb;
};
class Listbox : public wxFrame
{
public:
	Listbox(const wxString& title);
  void OnExit(wxCommandEvent& event);
  wxListBox *listbox;
	MyPanel *btnPanel;

};
const int ID_LOAD = 1;
const int ID_LISTBOX = 5;

#include <wx/textdlg.h>
Listbox::Listbox(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(1000, 500))
{
	wxPanel * panel = new wxPanel(this, -1);
	wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
	listbox = new wxListBox(panel, ID_LISTBOX,
		wxPoint(-1, -1), wxSize(-1, -1));
	hbox->Add(listbox, 3, wxEXPAND | wxALL, 20);
	btnPanel = new MyPanel(panel);
	hbox->Add(btnPanel, 2, wxEXPAND | wxRIGHT, 10);
	Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED,
	  wxCommandEventHandler(Listbox::OnExit));
  panel->SetSizer(hbox);

	Center();
}
MyPanel::MyPanel(wxPanel * parent)
	: wxPanel(parent, wxID_ANY)
{
	wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
	Listbox *lb = (Listbox *) parent->GetParent();
	m_lb = lb->listbox;
	m_newb = new wxButton(this, wxID_NEW, wxT("Новая игра"));
	m_loadb = new wxButton(this, ID_LOAD, wxT("Загрузить"));
  m_exitb = new wxButton(this, wxID_EXIT, wxT("Выход"));
	Connect(wxID_NEW, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(MyPanel::OnNew) );
	Connect(ID_LOAD, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(MyPanel::OnLoad));

	vbox->Add(-1, 20);
	vbox->Add(m_newb);
	vbox->Add(m_loadb, 0, wxTOP, 5);
  vbox->Add(m_exitb, 0, wxTOP, 5);
	SetSizer(vbox);
}
void MyPanel::OnNew(wxCommandEvent& event)
{
	wxString str = wxGetTextFromUser(wxT("Введите название игры"));
	if (str.Len() > 0)
		m_lb->Append(str);
    m_lb->Append("Game Started");
}
void Listbox::OnExit(wxCommandEvent& event)
{
	wxMessageDialog *dial = new wxMessageDialog(NULL,
		wxT("Вы точно хотите выйти?"), wxT("Question"),
	wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
	dial->SetYesNoLabels(_("&No"), _("&Yes"));
	if(dial->ShowModal() == wxID_NO)
	{
		Close(true);
	}
}
void MyPanel::OnLoad(wxCommandEvent& event)
{
	wxMessageBox( wxT("Load") );
}

class MyApp : public wxApp
{
	public:
		virtual bool OnInit();
};
IMPLEMENT_APP(MyApp)
bool MyApp::OnInit()
{
	Listbox *listbox = new Listbox(wxT("Roborace"));
	listbox->Show(true);
	return true;
}
