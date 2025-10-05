/*
Student ID:
Student Name: Raja M. Sumeer
Module: Object Orientated Programming @ Year 2, Semester 2 (Technological University Dublin)

Date: 09/02/2025

Exercise:
- 6

Code Purpose:
- Computes the mean & median of temperatures stored through vectors using called functions
*/
#include <iostream>
#include <vector>
#include <algorithm> // for sort()
using namespace std;

double mean(vector<double>);
double median(vector<double>);
int main() { // define & declare main loop
    vector<double> temperature;
    double temps;
    cout << "Enter some values:\n";
    while (cin >> temps) {
        temperature.push_back(temps);
    }
    cout << "Mean: " << mean(temperature);
    cout << "\n" << "Median: " << median(temperature) << endl;
    return 0;
}

double mean(vector<double> t) {
    double sum = 0.0;
    for (unsigned i = 0; i < t.size(); i++) {
        sum += t[i];
    }
    return (sum/t.size());
}

double median(vector<double> t) {
    sort(t.begin(), t.end());
    if (t.size() % 2 != 1) {
        return (t[t.size() / 2 - 1]);
    } else {
        return (t[t.size() / 2]);
    }
}
