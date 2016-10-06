#include "app.h"

Cblock::Cblock(){

}


Area Cblock::getsize(float x,float y){

return Area(10,10,100,10);
}

void Cblock::itemdraw(const Cairo::RefPtr<Cairo::Context>& cr){

drawc(cr,100,10,50);
}
