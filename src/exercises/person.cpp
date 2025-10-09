/*
Student ID:
Student Name: Raja M. Sumeer
Module: Object Orientated Programming @ Year 2, Semester 2 (Technological University Dublin)

Date: 02/03/2025

Exercise:
L07:
- 3

Code Purpose:
- Using classes, member functions to process a person information program
*/
#include <iostream>
using namespace std;
class Person {
private:
    string name, country;
    int age;
public:
    void setter(string n, string c, int a) {
        name = n;
        country = c;
        age = a;
    }
    void getter() {
        cout << "\nName: " << name << "\n" << "Country: " << country << "\n" << "Age: " << age;
    }
};

int main() {
    string name, country;
    int age;
    cout << "Give your name, country and age:\n";
    cin >> name >> country >> age;
    Person person;
    person.setter(name, country, age);
    person.getter();
    return 0;
}
