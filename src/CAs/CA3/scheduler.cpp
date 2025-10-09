/*
Student ID:
Student Name: Raja M. Sumeer
Module: Object Orientated Programming @ Year 2, Semester 2 (Technological University Dublin)

CA03 - Events & Meetings
scheduler.cpp - implementation file for Scheduler header

Last modified: 31/03/2025 @01:32

Sources (across all files):
- Lectures: 07-11
- bool: Lecture 07
- setfill: https://cplusplus.com/reference/iomanip/setfill/?kw=setfill
- getline: https://www.geeksforgeeks.org/getline-string-c/
- stoi: https://www.geeksforgeeks.org/stdstoi-function-in-cpp/
- ifs: Lecture 09
- Classes & Enums: Lecture 07
- I/Os: Lecture 08
- Inheritance: Lecture 10
*/
#include "scheduler.h"
#include <cstdlib> // for exit()
#include <string>
#include <fstream>

using namespace std;
namespace scheduler {

/* Invalid date check using boolean: definition
- Checks if days within logical range, including short day months
- Checks if year is within logical past & future range
*/
bool Date::checkDate(int yy, Month mm, int dd) {
    if (dd <= 0 || dd > 31 ) {
        return false;
    }
    if (mm < jan || mm > dec) {
        return false;
    }
    if (mm == apr || mm == jun || mm == sep || mm == nov && dd > 30) {
        return false;
    }
    if (yy < 2024 || y >= 2030) {
        return false;
    }
    return true;
}

/* Invalid Time check using boolean: definition
- Checks if hours within logical range of a day (24hrs)
- Checks if minutes within logical range (60s)
*/
bool Time::checkHour(int hh, int mm) {
    if (hh < 0 || hh > 23) {
        return false;
    }
    if (mm > 60) {
        return false;
    }
    return true;
}

/* LOAD function: defintion
- Reads meeting records from text files and returns a vector of Meeting objects
*/
vector<Meeting> load(string file) {
    /* In: file stream: open, check & read */
    ifstream ifs;
    ifs.open(file);
    if (!ifs.is_open()) {
        cerr << "Oops! Could not open: " << file << "\n";
        exit(-1);
    }

    vector<Meeting> meetings; // meeting objects vector

    /* Declare variables for storing read line content */
    string currentlyunused, date, start_time, end_time, location, chair, fileline,
           startHour, startMinute, endHour, endMinute, dateYear, dateMonth, dateDay, attendee;

    /* Get matching enum Month */
    Date::Month monthEnum;

    /* Read each file lines & store in string */
    while (getline(ifs, fileline)) {
        /* Stringstream to get each delimiter (,) seperated lines */
        stringstream ss(fileline);

        /* getline:
        Split line content into strings with delimiter */
        getline(ss, currentlyunused, ',');
        getline(ss, date, ',');
        getline(ss, start_time, ',');
        getline(ss, end_time, ',');
        getline(ss, location, ',');
        getline(ss, chair, ',');

        stringstream getDateMonth(date);
        getline(getDateMonth, dateYear, '-');
        getline(getDateMonth, dateMonth, '-');
        getline(getDateMonth, dateDay, ',');
        /* stoi():
        Convert string line into integers */
        int getDay = stoi(dateDay);
        int getYear = stoi(dateYear);

        stringstream getStartTime(start_time);
        getline(getStartTime, startHour, ':');
        getline(getStartTime, startMinute, ',');
        int getStartHour = stoi(startHour);
        int getStartMinute = stoi(startMinute);

        stringstream getEndTime(end_time);
        getline(getEndTime, endHour, ':');
        getline(getEndTime, endMinute, ',');
        int getEndHour = stoi(endHour);
        int getEndMinute = stoi(endMinute);

        /* Set correct enum from read string line */
        if (dateMonth == "01") {
            monthEnum = Date::jan;
        } else if (dateMonth == "02") {
            monthEnum = Date::feb;
        } else if (dateMonth == "03") {
            monthEnum = Date::mar;
        } else if (dateMonth == "04") {
            monthEnum = Date::apr;
        } else if (dateMonth == "05") {
            monthEnum = Date::may;
        } else if (dateMonth == "06") {
            monthEnum = Date::jun;
        } else if (dateMonth == "07") {
            monthEnum = Date::jul;
        } else if (dateMonth == "08") {
            monthEnum = Date::aug;
        } else if (dateMonth == "09") {
            monthEnum = Date::sep;
        } else if (dateMonth == "10") {
            monthEnum = Date::oct;
        } else if (dateMonth == "11") {
            monthEnum = Date::nov;
        } else if (dateMonth == "12") {
            monthEnum = Date::dec;
        }

        /* Date, Time & Meeting objects */
        Date meetingDate(getYear, monthEnum, getDay);

        Time meetingStartTime(getStartHour, getStartMinute);
        Time meetingEndTime(getEndHour, getEndMinute);

        Meeting meeting(meetingDate, meetingStartTime, meetingEndTime, location, chair);

        /* Get attendee lines and push to attendee vector for Meeting */
        while (getline(ss, attendee, ',')) {
            meeting.add_attendee(attendee);
        }

        /* Push Meeting object to vector */
        meetings.push_back(meeting);
    }
    /* Close file and return meeting objects */
    ifs.close();
    return meetings;
}
} // end of LOAD function