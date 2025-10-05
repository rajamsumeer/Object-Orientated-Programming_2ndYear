/*
Student ID:
Student Name: Raja M. Sumeer
Module: Object Orientated Programming @ Year 2, Semester 2 (Technological University Dublin)

Date: 19/02/2025

# CA01
Step 5:
bigsmall.cpp

Code Purpose:
- A program that continously takes in currency & amount from user and converts it to euro using
conversion header file that contains our functions for converting to / from euro
- Program also checks which euro value is the smallest / largest,
printing out converison result & difference

Currency Rates Updated: 21/02/2025
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include "conversion_functions.h" // header file for conversion functions
#include "robustness_checker.h" // robustness checker header file
using namespace std;

// declare function for getting the smallest / largest euro from conversion
void smallestORlargest(vector<double>& convertedRates, double & smallestEuro, double & largestEuro);

int main() { // define & declare main loop
    string currency;
    double amount;
    vector<double> convertedRates;

    cout << "Enter a currency followed by amount: (USD, JPY, CNY or STG)\n";
    while (cin >> currency >> amount) {
        // Check if user has given a currency not defined in conversion functions
        badCurrency(currency);
        // Check if user has given negative values
        negativeAmount(amount);
        double convertedAmount = to_euro(amount, currency);
        convertedRates.push_back(convertedAmount);

        // Find smallest / largest euro from conversion
        double smallestEuro, largestEuro;
        smallestORlargest(convertedRates, smallestEuro, largestEuro);

        cout << fixed << setprecision(2);
        if (convertedAmount == smallestEuro) {
            cout << "Result: " << convertedAmount << " Euro" << " (smallest so far)\n";
        } else if (convertedAmount == largestEuro) {
            cout << "Result: " << convertedAmount << " Euro" << " (largest so far)\n";
        }
    }
    return 0;
}

/*
- defining function
@param convertedRates The vector containing pushed user input values
@param smallestEuro The smallest euro value
@param largestEuro The largest euro value
*/
void smallestORlargest(vector<double>& convertedRates, double& smallestEuro, double& largestEuro) {
    smallestEuro = convertedRates[0];
    largestEuro = convertedRates[0];

    for (int i = 1; i < convertedRates.size(); i++) {
        if (convertedRates[i] < smallestEuro) {
            smallestEuro = convertedRates[i];
        }
    }

    for (int i = 1; i < convertedRates.size(); i++) {
        if (convertedRates[i] > smallestEuro) {
            largestEuro = convertedRates[i];
        }
    }
}