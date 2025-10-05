/*
Student ID:
Student Name: Raja M. Sumeer
Module: Object Orientated Programming @ Year 2, Semester 2 (Technological University Dublin)

harness.cpp - Part 1 test file
Simulating a 2-dimensional (x, y) point.
Using a Point class.

Last modified: 15/03/2025 @15:21
*/
#include <iostream>
#include <math.h> // for M_PI
#include "Point.h"

using namespace std;
using namespace geom;

int main()
{
    Point p1(3.0,5.0);

    p1.translate(-1.0, 1.0);

    cout << p1 << "\n"; // should print (2, 6)

    Point p2(p1);

    cout << p1 << "\n"; // should print (2,6)

    p2.rotate((Point) {
        1,1
    }, 90*M_PI/180);

    cout << p2 << "\n"; // should print (-4,2)

    cout << p1.distance(p2) << "\n"; // should print 7.2111

    return 0;
}