/*
Student ID:
Student Name: Raja M. Sumeer
Module: Object Orientated Programming @ Year 2, Semester 2 (Technological University Dublin)

Date: 12/03/2025

Exercise:
L09:
- 5

Code Purpose:
- Disemvowel a file and only return non-vowels

Sources:
-
*/
#include <iostream>
#include <fstream>
#include <cstdio> // for gets()

using namespace std;

class Invalid {
private:
public:
    bool check(char letter);
    void badName() {
        cerr << "Bad file name!\n";
        exit(-1);
    }
};

/* Check if letter is a vowel */
bool Invalid::check(char letter) {
    if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') {
        return false;
    }
    return true;
}

int main() {
    string fname;
    char letter;
    Invalid oops;

    cout << "Give the name of the file:\n";
    cin >> fname;

    /* Open file */
    ifstream ist(fname.c_str());

    // Error handling for file access
    if (!ist) {
        oops.badName();
    }

    /* Read characters, check for vowels and return vowel-less file contents*/
    while(ist.get(letter)) {
        if (oops.check(letter)) {
            cout << letter;
        }
    }
    ist.close();
    return 0;
}
