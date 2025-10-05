// Implementation file
#include "conversion_functions.h"
#include <iostream>
#include <string>
using namespace std;
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