#include "app.h"
Lineblock::Lineblock(){


}

Area Lineblock::getsize(float x,float y){

return Area(10,10,100,10);
}

void Lineblock::itemdraw(const Cairo::RefPtr<Cairo::Context>& cr){

drawblock(cr,100,50);
}
