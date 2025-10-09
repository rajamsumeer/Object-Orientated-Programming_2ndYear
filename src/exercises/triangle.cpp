/*
Student ID:
Student Name: Raja M. Sumeer
Module: Object Orientated Programming @ Year 2, Semester 2 (Technological University Dublin)

Date: 02/03/2025

Exercise:
L07:
- 5

Code Purpose:
- Using classes, member functions and validity checks to process a triangle program

Sources:
- Triangle checks:
https://www.w3resource.com/cpp-exercises/oop/cpp-oop-exercise-6.php#:~:text=The%20constructor%20Triangle%20initializes%20the,it%20as%20an%20equilateral%20triangle.

- Class bool check:
https://stackoverflow.com/questions/19835174/how-to-check-if-3-sides-form-a-triangle-in-c
*/
#include <iostream>
using namespace std;
class Triangle {
private:
    double one, two, three;
    bool check(double tone, double ttwo, double tthree);
public:
    class Invalid { };
    Triangle(double tone, double ttwo, double tthree) {
        one = tone;
        two = ttwo;
        three = tthree;
        if (!check(one, two, three))
            throw Invalid();
    }
    void equilateral() {
        if (one == two && two == three) {
            cout << "Triangle = Equilateral\n";
        }
    }
    void isosceles() {
        if (one == two || one == three || two == three) {
            cout << "Triangle = Isosceles\n";
        }
    }
    void scalene() {
        if ((one != two) && (one != three) && (two != three)) {
            cout << "Triangle = Scalene\n";
        }
    }
};

bool Triangle::check(double tone, double ttwo, double tthree) {
    if ((tone + ttwo > tthree) && (tone + tthree > ttwo) && (ttwo + tthree > tone)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    double one, two, three;

    cout << "Give 3 sides of a triangle:\n";
    cin >> one >> two >> three;

    try {
        Triangle triangle(one, two, three);
        triangle.equilateral();
        triangle.isosceles();
        triangle.scalene();
    }
    catch (Triangle::Invalid) {
        cerr << "bad triangle!\n";
    }

    return 0;
}
