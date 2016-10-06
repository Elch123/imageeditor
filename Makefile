all:
	g++ lineblock.cc main.cc codecanvas.cc codeblockdisp.cc cblock.cc -o app `pkg-config gtkmm-3.0 --cflags --libs`
