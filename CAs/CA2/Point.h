/*
Student ID:
Student Name: Raja M. Sumeer
Module: Object Orientated Programming @ Year 2, Semester 2 (Technological University Dublin)

Point.h - header file

Last modified: 15/03/2025 @15:21

Sources:
- atan2: https://www.gnu.org/software/libc/manual/html_node/Inverse-Trig-Functions.html
- hypot: https://www.gnu.org/software/libc/manual/html_node/Exponents-and-Logarithms.html
- rotate: Joeseph Obbong Oddi for breaking down the problem and understanding the solution
SOHCAHTOA
*/
#ifndef POINT_H
#define POINT_H

#include <cmath> // for atan2, hypot
#include <iostream>

using namespace std;

namespace geom {

class Point {
private:
    double xData, yData;
public:
    /* Constructors */
    Point(double xArg, double yArg) {
        xData = xArg;
        yData = yArg;
    }

    Point(const Point& otherPoint) {
        xData = otherPoint.x();
        yData = otherPoint.y();
    }

    /* Return x coordinate */
    double x() const {
        return xData;
    }
    /* Return y coordinate */
    double y() const {
        return yData;
    }
    /* Return angle between the x, y point */
    double angle() const {
        return atan2(yData, xData);
    }
    /* Return the radius from origin to point */
    double radius() const {
        return hypot(xData, yData);
    }

    /* Return the distance between point and another point */
    double distance(const Point& point2) const {
        double x = point2.x() - xData;
        double y = point2.y() - yData;
        return hypot(x, y);
    }

    /* Move a Point(x, y) coordinates by an amount */
    void translate(double dx, double dy) {
        xData += dx;
        yData += dy;
    }

    /* Rotate member function which rotates the point in 2D space by an amount theta about the origin.
    [in Radians]*/
    void rotate(double theta) {
        double thisAngle = angle();
        double newAngle = thisAngle + theta;

        double hypotoneuse = radius();
        double adjacent = cos(newAngle) * hypotoneuse;
        double opposite = sin(newAngle) * hypotoneuse;

        double x, y;
        x = adjacent;
        y = opposite;

        xData = x;
        yData = y;
    }

    /* Rotate member function which rotates the point in 2D space by an amount theta about the point p. */
    void rotate(const Point& point, double theta) {
        translate(-point.x(), -point.y());
        rotate(theta);
        translate(point.x(), point.y());
    }

    /* Overloading the << operator */
    friend ostream& operator<<(ostream& os, const Point& point) {
        os << "(" << point.x() << ", " << point.y() << ")";
        return os;
    }
};

}

#endif // POINT_H