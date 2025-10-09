/*
Student ID:
Student Name: Raja M. Sumeer
Module: Object Orientated Programming @ Year 2, Semester 2 (Technological University Dublin)

Date: 05/02/2025

Exercise:
- 7

Code Purpose:
- A tiny calculator that does calculations for + - / operators on two floating input numbers
- Zero division detection on 2nd input for division operator
- Switch case calculator

*/
#include <iostream>
using namespace std;
int main() { // define & declare main loop
    string operation; // store operator in string
    string operatorArray[] = {"+", "-", "/"}; // string array to store string operators
    float num1, num2; // declare floating input variables for user number inputs
    float result; // declare floating result of user's number inputs
    int i; // declare variable for for loop
    cout << "Select an operator: + - /\n";
    cin >> operation;
    cout << "Enter two numbers to perform the selected operator on:\n";
    cin >> num1 >> num2;
    if (operation == "/" && num2 == 0) {
        cerr << "Divison by zero detected!";
        return 1;
    }
    for (i = 0; i < 3; i++) { // i = 3 as array only has 3 elements to iterate through
    // if input operator matches an array element (operator)
    if (operation == operatorArray[i]) {
        switch (i) {
            case 0:
            result = num1 + num2;
            cout << "Addition Result: " << result;
            break;

            case 1:
            result = num1 - num2;
            cout << "Subtraction Result: " << result;
            break;

            case 2:
            result = num1 / num2;
            cout << "Division Result: " << result;
            break;
            default:
            cout << "That is not a valid operator!";
            }
        }
    }
return 0;
}
