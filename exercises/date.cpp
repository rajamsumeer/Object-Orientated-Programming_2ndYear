/*
Student ID:
Student Name: Raja M. Sumeer
Module: Object Orientated Programming @ Year 2, Semester 2 (Technological University Dublin)

Date: 02/03/2025

Exercise:
L07:
- 6

Code Purpose:
- A full date class, constructor, member functions, enumerators, overloading nd validity checks

Sources:
- Destructors
https://www.geeksforgeeks.org/destructors-c/
*/
#include <iostream>
using namespace std;

class Date {
private:
    int y;
    Month m;
    int d;
public:
    enum Month { jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

    class Invalid {};

    Date(int yy, Month mm, int dd) : y(yy), m(mm), d(dd) {
        if (!check(y, m, d)) throw Invalid();
    }

    // getters
    int year() const {
        return y;
    }
    Month month() const {
        return m;
    }
    int day() const {
        return d;
    }

    ~Date() {
        cout << "\nDestructor executed!";
    }

    void add(int d) {
        d++;
    }

    //overload == operator
    bool operator==(const Date& a, const Date& b) {
        return a.year()==b.year()
               && a.month()==b.month()
               && a.day()==b.day();
    }

    //overload << operator

    // overload ++ operator
    Month operator++(Month& m) {
        m = (m==dec) ? jan : Month(m+1);
        return m;
    }
};

bool Date::check(int yy, Month mm, int dd) {
    if (mm < 1 || mm > 12) return false;
    if (dd < 1 || dd > 31) return false;
    if (yy < 0) return false;
    return true;
}

int main() {
    try {
        Date my_birthday(2020, Date::jan, 1);
        cout << my_birthday.month() << endl;
    } catch (Date::Invalid) {
        cerr << "Bad date!\n";
    }

    return 0;
}
