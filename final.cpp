#include <wx/wx.h>

class Regions : public wxFrame
{
public:
	Regions(const wxString & title, int size);
	void OnPaint(wxPaintEvent & event);

	int cell_size;

	void OnMouseEvent( wxMouseEvent& event );
};


Regions::Regions(const wxString& title, int size): wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(270, 220))
{
	this->Connect(wxEVT_PAINT, wxPaintEventHandler(Regions::OnPaint));
	this->Centre();
	cell_size = size;

	//wxPanel* mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition);
	
	this->Connect(wxEVT_LEFT_UP, wxMouseEventHandler(Regions::OnMouseEvent));
}
	
void Regions::OnMouseEvent(wxMouseEvent& event)
{
    const wxPoint pt = wxGetMousePosition();
	int mouseX = pt.x - this->GetScreenPosition().x;
	int mouseY = pt.y - this->GetScreenPosition().y;

	wxPaintDC dc(this);
    //wxMessageBox(wxString::Format("x: %i, y: %i",mouseX, mouseY));
   	
   	wxColour red;

	red.Set(wxT("#ff0000"));
	
    dc.SetBrush(wxBrush(red));	
    dc.DrawRectangle(mouseX, mouseY, cell_size, cell_size);

    //event.Skip();
}

void Regions::OnPaint(wxPaintEvent & event)
{
   	wxPaintDC dc(this);
	wxColour gray, white, red, blue;
	wxColour orange, green, brown;
	gray.Set(wxT("#d4d4d4"));
	white.Set(wxT("#ffffff"));
	red.Set(wxT("#ff0000"));
	orange.Set(wxT("#fa8e00"));
	green.Set(wxT("#619e1b"));
	brown.Set(wxT("#715b33"));
	blue.Set(wxT("#0d0060"));

	dc.SetPen(wxPen(gray));
  for (int i = 0; i <= 33; i++)
  {
    for (int j = 0; j <= 17	; j++)
    {
      dc.DrawRectangle(cell_size*i, cell_size*j, cell_size, cell_size);
    }
  }
}

class MyApp : public wxApp
{
	public:
		virtual bool OnInit();
};


IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
	Regions *regions = new Regions(wxT("Regions"), 40);
	regions->Show(true);
	return true;
}






/*dc.DrawRectangle(20, 20, 50, 50);
	dc.DrawRectangle(30, 40, 50, 50);
	dc.SetBrush(wxBrush(white));
	dc.DrawRectangle(100, 20, 50, 50);
	dc.DrawRectangle(110, 40, 50, 50);
	wxRegion region1(100, 20, 50, 50);
	wxRegion region2(110, 40, 50, 50);
	region1.Intersect(region2);
	wxRect rect1 = region1.GetBox();
	dc.SetClippingRegion(region1);
	dc.SetBrush(wxBrush(red));
	dc.DrawRectangle(rect1);
	dc.DestroyClippingRegion();
	dc.SetBrush(wxBrush(white));
	dc.DrawRectangle(180, 20, 50, 50);
	dc.DrawRectangle(190, 40, 50, 50);
	wxRegion region3(180, 20, 50, 50);
	wxRegion region4(190, 40, 50, 50);
	region3.Union(region4);
	dc.SetClippingRegion(region3);
	wxRect rect2 = region3.GetBox();
	dc.SetBrush(wxBrush(orange));
	dc.DrawRectangle(rect2);
	dc.DestroyClippingRegion();
	dc.SetBrush(wxBrush(white));
	dc.DrawRectangle(20, 120, 50, 50);
	dc.DrawRectangle(30, 140, 50, 50);
	wxRegion region5(20, 120, 50, 50);
	wxRegion region6(30, 140, 50, 50);
	region5.Xor(region6);
	wxRect rect3 = region5.GetBox();
	dc.SetClippingRegion(region5);
	dc.SetBrush(wxBrush(green));
	dc.DrawRectangle(rect3);
	dc.DestroyClippingRegion();
	dc.SetBrush(wxBrush(white));
	dc.DrawRectangle(100, 120, 50, 50);
	dc.DrawRectangle(110, 140, 50, 50);
	wxRegion region7(100, 120, 50, 50);
	wxRegion region8(110, 140, 50, 50);
	region7.Subtract(region8);
	wxRect rect4 = region7.GetBox();
	dc.SetClippingRegion(region7);
	dc.SetBrush(wxBrush(brown));
	dc.DrawRectangle(rect4);
	dc.DestroyClippingRegion();
	dc.SetBrush(white);
	dc.DrawRectangle(180, 120, 50, 50);
	dc.DrawRectangle(190, 140, 50, 50);
	wxRegion region9(180, 120, 50, 50);
	wxRegion region10(190, 140, 50, 50);
	region10.Subtract(region9);
	wxRect rect5 = region10.GetBox();
	dc.SetClippingRegion(region10);
	dc.SetBrush(wxBrush(blue));
	dc.DrawRectangle(rect5);
	dc.DestroyClippingRegion();
  wxPoint points[3];
  points[0] = wxPoint(200,200);
  points[1] = wxPoint(250,250);
  points[2] = wxPoint(305,355);
  //points[3] = wxPoint(305,305);
  dc.SetBrush(orange);
	dc.DrawPolygon(3, points);*/


