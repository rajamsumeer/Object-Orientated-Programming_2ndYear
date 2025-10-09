/*
Student ID:
Student Name: Raja M. Sumeer
Module: Object Orientated Programming @ Year 2, Semester 2 (Technological University Dublin)

## CA04 - Chessboard & PPPGUI
chessboard.cpp - Implementation file
Shape based off Student ID: Rectangle

## Last modified: 20/04/2025 @01:45

## Sources (across all files):
- PPPGUI (share folder) e.g Graph.h
- Lectures 07-14
- bool: Lecture 07
- Classes: Lecture 07
- Inheritance: Lecture 10
- Polymorphism: Lecture 11
- Composition & Aggregation: Lecture 12
- CA03

## Additional Comments:
- Graph.h's Rectangle has an undefined constructor error 
that needs to be commented out before running this program
*/
#include "Simple_window.h"
#include "Graph.h"
#include "chessboard.h"
#include <iostream>

using namespace std;
using namespace Graph_lib;
int main()
{
    /* Create window with coordinates */
    Simple_window win(Point(100,100), 600, 400, "Chessboard: S.ID");

    /* Default Chessboard Object: 8x8, Black and White */
    Chessboard c1(Point(20, 20));
    /* Custom Size Chessboard Object: 10x10, Black and White */
    Chessboard c2(Point(140, 140), 160, 160, 10);
    /* Custom Size & Color Chessboard Object: 6x6, Yellow and Red */
    Chessboard c3(Point(340, 200), 120, 120, 6, Color::yellow, Color::red);
    
    try {
        /* Attach Chessboard Objects */
        win.attach(c1);
        win.attach(c2);
        win.attach(c3);
    }
    catch (BadChessboardException e) {
        cerr << "Bad chessboard.\n";
    }    
    /* Exit */
    win.wait_for_button();

}
