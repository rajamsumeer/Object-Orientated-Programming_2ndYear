/*
Student ID:
Student Name: Raja M. Sumeer
Module: Object Orientated Programming @ Year 2, Semester 2 (Technological University Dublin)

Date: 09/03/2025

Exercise:
L08:
- 4

Code Purpose:
- Write a function that checks which error states have been set to throw an exception,
and returns a short string.

Sources:
- Lecture 8 I/O
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function declaration to return exceptions as string.
string exceptions_to_str(const ios& stream);

int main() {
    cin.exceptions(ifstream::failbit | ifstream::badbit);
    // Check the exceptions set for cin
    cout << exceptions_to_str(cin) << endl;
    return 0;
}

/*
Function definition to return exceptions as string.
@@param ios: stream
*/
string exceptions_to_str(const ios& stream) {
    ios::iostate exception_mask = stream.exceptions();

    if (exception_mask & ios::badbit) {
        return "Exception thrown if state is bad.\n";
    }

    if (exception_mask & ios::eofbit) {
        return "Exception thrown if state is eof.\n";
    }

    if (exception_mask & ios::failbit) {
        return "Exception thrown if state is fail.\n";
    }
    return "No exception thrown.\n";
}
