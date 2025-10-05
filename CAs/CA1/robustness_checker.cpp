// Implementation file
#include "robustness_checker.h"
#include <iostream>
#include <string>
#include <cstdlib>  // for exit()
using namespace std;
void badConversionType(string convertType) {
    if (convertType != "toeuro" && convertType != "fromeuro") {
        cerr << "Bad conversion type!\n";
    }
}

void negativeAmount(double amount) {
    if (amount < 0) {
        cerr << "Amount may not be negative!\n";
        exit(EXIT_FAILURE);
    }
}

void badCurrency(string currency) {
    if (currency != "USD" && currency != "JPY" && currency != "STG" && currency != "CNY") {
        cerr << "Bad currency!\n";
        exit(EXIT_FAILURE);
    }
}