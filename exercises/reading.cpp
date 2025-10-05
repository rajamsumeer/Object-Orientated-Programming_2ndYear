/*
Student ID:
Student Name: Raja M. Sumeer
Module: Object Orientated Programming @ Year 2, Semester 2 (Technological University Dublin)

Date: 09/03/2025

Exercise:
L08:
- 2

Code Purpose:
- Read a file of hour & temperature records and store them in a Reading object.

Sources:
-
*/
#include <iostream>
#include <fstream> // for ifstream
#include <vector>
#include <string>
#include <cstdlib> // for exit()
using namespace std;

struct Reading {
    int hour;
    double temperature;

    // Reading constructor
    Reading(int h, double t) {
        hour = h;
        temperature = t;
    }
};

// Overload >> operator to read each record from file
istream& operator>>(istream& ist, Reading& read) {
    int h;
    double t;

    if (ist >> h >> t) {
        read = Reading(h, t);
    }
    return ist;
}

int main() {
    vector<Reading> temps;
    string fname;
    int hour;
    double temperature;

    Reading read(hour, temperature);

    cout << "Give the name of the file:\n";
    cin >> fname;

    ifstream ist(fname.c_str());

    // Error handling for file access
    if (!ist) {
        cerr << "Can't open the file you entered.\n";
        exit(-1);
    }

    // Read records from file
    while (ist >> read) {
        if (hour < 0 || 23 < hour) {
            cerr << "Hour out of range!\n";
            exit(-1);
        }
        temps.push_back(Reading(hour, temperature));
    }

    // Check for EOF
    if (ist.eof()) {
        cout << "End of file reached.\n";
    }

    cout << "Records read: " << temps.size() << endl;
    return 0;
}
