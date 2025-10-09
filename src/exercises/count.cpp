/*
Student ID:
Student Name: Raja M. Sumeer
Module: Object Orientated Programming @ Year 2, Semester 2 (Technological University Dublin)

Date: 09/03/2025

Exercise:
L08:
- 3

Code Purpose:
- Write a program that counts the words in a file.

Sources:
- Gareth lecture 8 I/O
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Invalid {
public:
    void badName() {
        cerr << "Bad file name!\n";
        exit(-1);
    };
};

int main() {
    string fname, words;
    int count = 0;

    Invalid oops;

    cout << "Give the name of the file:\n";
    cin >> fname;

    ifstream ist(fname.c_str());

    // Error handling for file access
    if (!ist) {
        oops.badName();
    }

    // count words from file
    while (ist >> words) {
        count++;
    }

    // Check for EOF
    if (ist.eof()) {
        cerr << "End of file reached.\n";
    }

    cout << "Word count of the file: " << count << endl;
    ist.close();
    return 0;
}
