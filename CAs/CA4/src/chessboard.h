/*
Student ID:
Student Name: Raja M. Sumeer
Module: Object Orientated Programming @ Year 2, Semester 2 (Technological University Dublin)

## CA04 - Chessboard & PPPGUI
chessboard.h - Header file
Shape based off Student ID: Rectangle

## Last modified: 20/04/2025 @01:45

## Sources (across all files):
- PPPGUI (share folder) e.g Graph.h
- Lectures: 07, 08, 09, 10, 11, 12, 13, 14
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
#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include "Graph.h"
#include <iostream>

using namespace std;
using namespace Graph_lib;

/* Chessboard Class using PPPGUI */
class BadChessboardException { };
class Chessboard: public Shape {
public:
/* Chessboard Constructors for different arguments with validty checks.
- place from top left of window
- default, custom size and with different square colors */
Chessboard(Point winleft) : wpoint(winleft), w(100), h(100), squares_H_V(8), square1(Color::white), square2(Color::black) {
    if (!checkSize(squares_H_V, w, h)) {
        throw BadChessboardException();
    }
}

Chessboard(Point winleft, int width, int height, int squares) : wpoint(winleft), w(width), h(height), squares_H_V(squares), square1(Color::white), square2(Color::black) {
    if (!checkSize(squares_H_V, w, h)) {
        throw BadChessboardException();
    }
}

Chessboard(Point winleft, int width, int height, int squares, Color sq1, Color sq2) : wpoint(winleft), w(width), h(height), squares_H_V(squares), square1(sq1), square2(sq2) {
    if (!checkSize(squares_H_V, w, h)) {
        throw BadChessboardException();
    }
}

/* Destructor: Deallocate Memory & Clean up Chessboard Class Object */
~Chessboard() {
    cout << "Destructing Chessboard\n";
}

/* Getters for Square Width, Height */
int getSquareWidth(void) const {
    int width = w / squares_H_V;
    return width;
}
int getSquareHeight(void) const {
    int height = h / squares_H_V;
    return height;
}

/* Member Functions for Handling Color & Square Draw Lines */
void draw_squares(Point point, Color squareColor) const {
    int width = Chessboard::getSquareWidth();
    int height = Chessboard::getSquareHeight();
    Rectangle square(point, Point(point.x + width, point.y + height));
    square.set_fill_color(squareColor);
    square.set_color(Color::black);
    square.draw();
}
void draw_lines() const { // override Shape draw_lines() since it's virtual
    int horizontal, vertical;
    // For each "row and column" of Chessboard
    for (horizontal = 0; horizontal < squares_H_V; horizontal++) {
        for (vertical = 0; vertical < squares_H_V; vertical++) {
            int width = Chessboard::getSquareWidth();
            int height = Chessboard::getSquareHeight();
            // Draw Squares at Point & Fill Colour using Ternary Operator
            Chessboard::draw_squares(Point(wpoint.x + width * vertical, wpoint.y + height * horizontal), ((horizontal + vertical) % 2 != 1) ? square1 : square2);
        }
    }
}
/* Data Members */
private:
Point wpoint;
int w;
int h;
int squares_H_V;
Color square1, square2;
bool checkSize(int squares_H_V, int w, int h);
};

/* Chessboard Checker Definition
- Checks for valid Chessboard squares size, width and height values using bool
- False returns will throw BadChessboardException
*/
bool Chessboard::checkSize(int squares_H_V, int w, int h) {
    if (squares_H_V <= 0 || h <= 0 || w <= 0) {
        return false;
    }
    return true;
}
#endif