/*
Student ID:
Student Name: Raja M. Sumeer
Module: Object Orientated Programming @ Year 2, Semester 2 (Technological University Dublin)

Date: 09/03/2025

Exercise:
L08:
- 5

Code Purpose:
- Write a function which returns a string version of the stream state.

Sources:
- Lecture 8 I/O
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function declaration to return steam state as string.
string state_to_str(istream &st);

class Invalid {
public:
    void badName() {
        cerr << "Bad file name!\n";
        exit(-1);
    };
};

int main() {
    string fname;

    cout << "Give the name of the file:\n";
    cin >> fname;

    Invalid oops; // create object

    ifstream ist(fname.c_str());

    // Error handling for file access
    if (!ist) {
        oops.badName();
    }

    // Check the state of the stream
    cout << state_to_str(ist) << endl;
    return 0;
}

/*
Function definition to return steam state as string.
@@param istream: st
@@state: string
@@state: four states checker of iostream
*/
string state_to_str(istream &st) {
    string state;

    if (st.good()) {
        state = "Stream state: good.";
    }

    if (st.eof()) {
        state = "Stream state: eof fail.";
    }

    if (st.fail()) {
        state = "Stream state: fail.";
    }

    if (st.bad()) {
        state = "Stream state: bad.";
    }
    return state;
}
