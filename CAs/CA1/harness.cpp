/*
Student ID:
Student Name: Raja M. Sumeer
Module: Object Orientated Programming @ Year 2, Semester 2 (Technological University Dublin)

Date: 19/02/2025

# CA01
harness.cpp

Code Purpose:
- A simple two way currency conversion between EUR and XXX using two functions called in main()
- User inputs currency & amount, where main() then prints out result.
- Program checks for user inputs, that are invalid e.g negative amounts

Currency Rates Updated: 21/02/2025
*/
#include <iostream>
#include <iomanip>
#include "robustness_checker.h" // robustness checker header file
using namespace std;

// declaring function for converting to other currencies from EURO
double from_euro(double amount, string currency);

// declaring function for converting currencies to EURO
double to_euro(double amount, string currency);

int main() {
    string currency, convertType;
    double amount;

    cout << "Type the preferred conversion: toeuro OR fromeuro\n";
    cin >> convertType;
    // If user enters a conversion type not accepted by program
    badConversionType(convertType);
    // Check which conversion type given and call required function & output result
    if (convertType == "toeuro") {
        cout << "(to_euro) Enter a currency: USD, JPY, CNY or STG:\n";
        cin >> currency;
        // Check if user has given a currency not defined in conversion functions
        badCurrency(currency);
        cout << "Enter an amount to convert:\n";
        cin >> amount;
        // Check if user has given negative values
        negativeAmount(amount);
        cout << fixed << setprecision(2);
        cout << "Result: " << to_euro(amount, currency) << " Euro" << endl;
    }

    if (convertType == "fromeuro") {
        cout << "(from_euro) Enter a currency: USD, JPY, CNY or STG:\n";
        cin >> currency;
        badCurrency(currency);
        cout << "Enter an amount to convert:\n";
        cin >> amount;
        negativeAmount(amount);
        cout << fixed << setprecision(2);
        cout << "Result: " << from_euro(amount, currency) << " " << currency << endl;
    }
    return 0;
}

/*
- defining function
@param currency The prefered currency for conversion
@param amount The amount to convert to
*/
double from_euro(double amount, string currency) {
    if (currency == "USD") {
        return (amount * 1.05);
    }
    if (currency == "JPY") {
        return (amount * 156.20);
    }
    if (currency == "STG") {
        return (amount * 0.83);
    }
    if (currency == "CNY") {
        return (amount * 7.58);
    }
    return 0;
}

/*
- defining function
@param currency The prefered currency for conversion
@param amount The amount to convert to
*/
double to_euro(double amount, string currency) {
    if (currency == "USD") {
        return (amount / 1.05);
    }
    if (currency == "JPY") {
        return (amount / 156.20);
    }
    if (currency == "STG") {
        return (amount / 0.83);
    }
    if (currency == "CNY") {
        return (amount / 7.58);
    }
    return 0;
}