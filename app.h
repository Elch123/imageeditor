#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED
#include <stdio.h>
#include <vector>
#include <iostream>
#include <gtkmm.h>
#include <math.h>
const int initw=10;
const int curves=4;
const int pthick=10;
const int ygap=4;
const int xgap=10;
class CodeBlockDisp;

class Elchimage : public Gtk::Grid{


};

class Point{
public:
Point(float a,float b){
x=a;y=b;
};
float x;
float y;
};

class Area{
public:
Area(float a,float b,float c,float d){
x=a;
y=b;
w=c;
h=d;
}
float x;
float y;
float w;
float h;
void print(){ 
std::cout << " "<< x << " "<< y  << " "<< w  << " "<< h << "\n";
}
};

class CommandImgHolder : public Gtk::Grid{
public:

protected:

};


class CodeCanvas : public Gtk::DrawingArea
{
public:
  CodeCanvas(CodeBlockDisp *d);
  virtual ~CodeCanvas();
  CodeBlockDisp *drawer;
protected:
  //Override default signal handler:
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

};


class CodeBlockDisp{
public:
CodeBlockDisp();
virtual ~CodeBlockDisp();
bool haschildren;
Area area=Area(0,0,0,0);
virtual void draw(const Cairo::RefPtr<Cairo::Context>& cr);
virtual Area getsize(float x,float y);
void addchild(CodeBlockDisp * element,int pos);
//CodeBlock findelement(int mouseX,int mouseY);
protected:
std::vector<CodeBlockDisp *> args; 
std::vector<CodeBlockDisp *> list;
virtual void itemdraw(const Cairo::RefPtr<Cairo::Context>& cr);
virtual void drawblock(const Cairo::RefPtr<Cairo::Context>& cr,float h, float l);
virtual void drawc(const Cairo::RefPtr<Cairo::Context>& cr,float h, float l,float midlength);
Point drawchildren(const Cairo::RefPtr<Cairo::Context>& cr);
};

class Cblock : public CodeBlockDisp{
public:
Cblock();
virtual Area getsize(float x,float y) override;
protected:
virtual void itemdraw(const Cairo::RefPtr<Cairo::Context>& cr) override;
};

class Lineblock : public CodeBlockDisp{
public:
Lineblock();
virtual Area getsize(float x,float y) override;
protected:
virtual void itemdraw(const Cairo::RefPtr<Cairo::Context>& cr) override;
};



#endif
