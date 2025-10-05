/*
Student ID:
Student Name: Raja M. Sumeer
Module: Object Orientated Programming @ Year 2, Semester 2 (Technological University Dublin)

Date: 12/03/2025

Exercise:
L09:
- 2

Code Purpose:
- Using setw to format output
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << 123456 <<'|'
    << setw(4) << 123456 << '|'
    << setw(8) << 123456 << '|'
    << 123456 << "|\n";
    cout << 1234.56 <<'|'
    << setw(4) << 1234.56 << '|'
    << setw(8) << 1234.56 << '|'
    << 1234.56 << "|\n";
    cout << "asdfgh" <<'|'
    << setw(4) << "asdfgh" << '|'
    << setw(8) << "asdfgh" << '|'
    << "asdfgh" << "|\n";
    return 0;
}
