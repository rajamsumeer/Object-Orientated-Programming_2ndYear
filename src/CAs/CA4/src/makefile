## Student ID:
CC = g++

PPPGUI_DIR = ./share/pppgui

CPPFLAGS = -g -I$(PPPGUI_DIR)/include
LDFLAGS  = -g
LDLIBS   = -L$(PPPGUI_DIR)/lib -lpppgui -lfltk -lfltk_images

all: chessboard.exe

chessboard.o: chessboard.cpp chessboard.h
	$(CC) -c -o $@ $(CPPFLAGS) $<

chessboard.exe: chessboard.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

clean:
	rm -f *.o *.exe