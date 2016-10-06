#include "app.h"

int main(int argc, char **argv){
auto app=Gtk::Application::create(argc,argv,"elch.ELCHATRON.drawingapp");
Gtk::Window window;
window.set_title("Elchanan's app");
Cblock ablock;
Lineblock child;
ablock.addchild((CodeBlockDisp *) &child,0);
CodeCanvas canvas((CodeBlockDisp *)&ablock);
window.add(canvas);
canvas.show();
return app->run(window);
}
