#include "app.h"

CodeBlockDisp::CodeBlockDisp(){


}

CodeBlockDisp::~CodeBlockDisp(){


}


void CodeBlockDisp::draw(const Cairo::RefPtr<Cairo::Context>& cr){
cr->save();
cr->translate(area.x,area.y);
itemdraw(cr);
drawchildren(cr);
cr->restore();

}

void CodeBlockDisp::itemdraw(const Cairo::RefPtr<Cairo::Context>& cr){

}

Area CodeBlockDisp::getsize(float x,float y){

Area size(x,y,pthick,pthick);
for(auto &i :  args){
Area child=i->getsize(size.w,ygap);
size.w+=child.w+xgap;
if(child.h>size.h+ygap/2) { size.h=child.h+ygap; }
}
area=size;
return size;
}

Point CodeBlockDisp::drawchildren(const Cairo::RefPtr<Cairo::Context>& cr){
for (auto &i : args){
i->draw(cr);
}
for (auto &i : list){
i->draw(cr);
}
}

void CodeBlockDisp::addchild(CodeBlockDisp * element,int pos){
if(pos==0){
args.push_back(element);
}
if(pos ==1){
list.push_back(element);
}
}


void CodeBlockDisp::drawblock(const Cairo::RefPtr<Cairo::Context>& cr,float l, float h){
cr->save();
cr->move_to(0,curves);
cr->arc(curves,curves,curves,M_PI,3*M_PI/2);
cr->line_to(l-curves,0);
cr->arc(l-curves,curves,curves,3*M_PI/2,0);
cr->line_to(l,h-curves);
cr->arc(l-curves,h-curves,curves,0,M_PI/2);
cr->line_to(curves,h);
cr->arc(curves,h-curves,curves,M_PI/2,M_PI);
cr->close_path();
cr->set_source_rgb(1,1,0);
cr->fill_preserve();
cr->set_source_rgb(1,0,1);
cr->stroke();
cr->restore();
}


void CodeBlockDisp::drawc(const Cairo::RefPtr<Cairo::Context>& cr,float l, float h,float midlength){
cr->save();
cr->move_to(0,curves);
cr->arc(curves,curves,curves,M_PI,3*M_PI/2);
cr->line_to(l-curves,0);
cr->arc(l-curves,curves,curves,3*M_PI/2,0);
cr->line_to(l,h-curves);
cr->arc(l-curves,h-curves,curves,0,M_PI/2);
cr->line_to(curves+pthick,h);
cr->arc_negative(curves+pthick,h+curves,curves,3*M_PI/2,M_PI);
cr->line_to(pthick,h+midlength-curves);
cr->arc_negative(curves+pthick,h+midlength-curves,curves,M_PI,M_PI/2);
cr->line_to(l-curves,h+midlength);
cr->arc(l-curves,h+midlength+curves,curves,3*M_PI/2,0);
cr->line_to(l,2*h+midlength-curves);
cr->arc(l-curves,2*h+midlength-curves,curves,0,M_PI/2);
cr->line_to(curves,2*h+midlength);
cr->arc(curves,2*h+midlength-curves,curves,M_PI/2,M_PI);
cr->close_path();
cr->set_source_rgb(1,1,0);
cr->fill_preserve();
cr->set_source_rgb(1,0,1);
cr->stroke();
cr->restore();
}
