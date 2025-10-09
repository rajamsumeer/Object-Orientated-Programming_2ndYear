/*
Student ID:
Student Name: Raja M. Sumeer
Module: Object Orientated Programming @ Year 2, Semester 2 (Technological University Dublin)

Date: 05/02/2025

Exercise:
- 5

Code Purpose:
- User enters 3 integer values and then sort them by ascending order & output result

*/
#include <iostream>
#include <algorithm> // for functions like sort()
using namespace std;
int main() { // define & declare main loop

int values[3]; // declare array to hold 3 int values
cout << "Please enter 3 integer numbers:\n";
// input 3 int values from user using a for loop
for (int i = 0; i < 3; i++) {
    cin >> values[i];
}
/*
cout << "Please enter 3 integer numbers:\n";
cin >> values[0] >> values[1] >> values[2];
*/
sort(values, values + 3); // sort from value 1 in array to last value
// print out sorted array elements using for loop
for (int i = 0; i < 3; i++) {
    cout << values[i] << ", ";
}
// cout << values[0] << ", " << values[1] << ", " << values[2];

return 0;
}
