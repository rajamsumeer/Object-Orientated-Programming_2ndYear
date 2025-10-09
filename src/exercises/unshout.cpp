/*
Student ID:
Student Name: Raja M. Sumeer
Module: Object Orientated Programming @ Year 2, Semester 2 (Technological University Dublin)

Date: 12/03/2025

Exercise:
L09:
- 6

Code Purpose:
- Read a file and output the contents in lowercase - if uppercase present.

Sources:
-
*/
#include <iostream>
#include <fstream>
#include <cctype> // for isupper()

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

/* Check if character is uppercase */
bool Invalid::check(char letter) {
    if (isupper(letter)) {
        return true;
    }
    return false;
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

    /* Read characters from file, check if uppercase and return file contents as lowercase */
    while(ist.get(letter)) {
        if (oops.check(letter)) {
            cout << (char)tolower(letter); // cast to lowercase
        } else {
            cout << letter;
        }
    }
    ist.close();
    return 0;
}
