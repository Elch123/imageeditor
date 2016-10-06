#include "app.h"

CodeCanvas::CodeCanvas(CodeBlockDisp *d)
{
drawer=d;

}

CodeCanvas::~CodeCanvas()
{
}

bool CodeCanvas::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  Gtk::Allocation allocation = get_allocation();
  const int width = allocation.get_width();
  const int height = allocation.get_height();
  drawer->getsize(0,0);
  drawer->draw(cr);
  return true;
}
