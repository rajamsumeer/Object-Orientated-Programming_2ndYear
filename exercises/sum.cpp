/*
Student ID:
Student Name: Raja M. Sumeer
Module: Object Orientated Programming @ Year 2, Semester 2 (Technological University Dublin)

Date: 15/02/2025

Exercise:
L05:
- 9

Code Purpose:
- Reads & stores a series of integers and computes the N sum of those integers from a int vector
- With EOF and NaN checks on user inputs
- Prints out computed result

Support Links:
- https://stackoverflow.com/questions/17928865/correct-way-to-use-cin-fail
> How to check for NaN in C++
- https://stackoverflow.com/questions/4939251/cin-eof-functionality
> cin.eof()
- https://stackoverflow.com/questions/17928865/correct-way-to-use-cin-fail
> cin.fail()
*/
#include <iostream>
#include <vector>
using namespace std;
class bad_argument { };
int main() { // define & declare main loop
    vector<int> inputs;
    int integers;

    // N
    cout << "How many numbers to be summed?\n";
    int sumAmount = 0;
    cin >> sumAmount;
    // check if sum amount is not an int/NaN
    if (cin.fail()) {
        cerr << "The sum amount should be an integer too!\n";
        throw bad_argument();
    }

    // inputs for N
    cout << "Please give some integer values to be summed!\n";
    while (cin >> integers) {
        inputs.push_back(integers);
    }

    // NaN & EOF check
    if (cin.eof()) {

    // N != inputs
    if (inputs.size() < sumAmount) {
        cerr << "You want to sum more than given integer inputs!\n";
        throw bad_argument();
    }

    // sum each element in vector
    int sum = 0;
    for (int i = 0; i < inputs.size(); i++) {
        sum += inputs[i];
    }
    cout << "Result: " << sum << endl;
    } else {
        if (cin.fail()) {
            cerr << "You entered something other than a integer?\n";
            throw bad_argument();
        }
    } // end of NaN & EOF check
    return 0; // return code 0
}
