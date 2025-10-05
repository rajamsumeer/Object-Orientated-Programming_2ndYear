/*
Student ID:
Student Name: Raja M. Sumeer
Module: Object Orientated Programming @ Year 2, Semester 2 (Technological University Dublin)

Date: 09/02/2025

Exercise:
- 4

Code Purpose:
- Compute calculations between two cities using vectors and for loops
*/
#include <iostream>
#include <vector>

using namespace std;
int main() { // define & declare main loop

    vector<double> distance;
    double distances;

    cout << "Enter distances:\n";

    while (cin >> distances) {
        distance.push_back(distances);
    }

    double totalDistance = 0.0;
    for (int i = 0; i < distance.size(); i++) {
        totalDistance += distance[i];
    }

    double smallestDistance = distance[0];
    for (int i = 1; i < distance.size(); i++) {
        if (distance[i] < smallestDistance) { smallestDistance = distance[i]; }
    }

    double largestDistance = distance[0];
    for (int i = 1; i < distance.size(); i++) {
        if (distance[i] > largestDistance) { largestDistance = distance[i]; }
    }

    double mean = totalDistance / distance.size();

    cout << "Total: " << totalDistance << "\n" << "S: " << smallestDistance << "\n" << "L: " << largestDistance << "\n" << "M: " << mean;
    
    return 0;
}
