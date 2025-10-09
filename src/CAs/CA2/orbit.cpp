/*
Student ID:
Student Name: Raja M. Sumeer
Module: Object Orientated Programming @ Year 2, Semester 2 (Technological University Dublin)

orbit.cpp - Part 2 main file
Simulate the Moon's orbit around the Earth over the course of a year.

Last modified: 15/03/2025 @15:21
*/

#include <cmath> // for M_PI
#include <iomanip> // for setprecision
#include <iostream>
#include "Point.h"

using namespace std;
using namespace geom;

#define PI M_PI
#define EARTH_POS 193000000.0 // 193 million km from Sun
#define MOON_POS 384000.0 // 384 thousand km from Earth

int main() {
    /* Earth: 360° in 365 days; Moon: 360° in 27 days
    1° / 365
    [in Radians] */
    double dailyEarthRotation = (2 * PI / 365.0);
    double dailyMoonRotation = (2 * PI / 27.0);

    /* Initial positions of Sun, Moon & Earth */
    Point Earth(EARTH_POS, 0);
    Point Moon(EARTH_POS + MOON_POS, 0);
    Point Sun(0, 0);

    /* Orbital Period: 365 days */
    for (int i = 0; i < 365; i++) {
        Earth.rotate(Sun, dailyEarthRotation);
        Moon.rotate(Sun, dailyEarthRotation);
        Moon.rotate(Earth, dailyMoonRotation);
        // Print X,Y coordinates of Earth & Moon with delimiter
        cout << fixed << setprecision(2);
        cout << i << ","
             << Earth.x() << "," << Earth.y() << ","
             << Moon.x() << "," << Moon.y() << "\n";
    }
    return 0;
}