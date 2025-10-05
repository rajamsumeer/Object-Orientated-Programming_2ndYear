/*
Student ID:
Student Name: Raja M. Sumeer
Module: Object Orientated Programming @ Year 2, Semester 2 (Technological University Dublin)

CA03 - Events & Meetings
scheduler.h - header file

Last modified: 31/03/2025 @01:32

Sources (across all files):
- Lectures: 07-11
- bool: Lecture 07
- setfill: https://cplusplus.com/reference/iomanip/setfill/?kw=setfill
- getline: https://www.geeksforgeeks.org/getline-string-c/
- ifs: Lecture 09
- Classes & Enums: Lecture 07
- I/Os: Lecture 08
- Inheritance: Lecture 10
- Event class print(): explanation by Dovydas Klisys, Joeseph Oddi Obong
*/
#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

namespace scheduler {

/* Date Class */
class Date {
public:
    enum Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };
    class Bad_Date { };
    /* Constructor */
    Date(int yy, Month mm, int dd) : y(yy), m(mm), d(dd) {
        if(!checkDate(y, m, d)) {
            throw Bad_Date();
        }
    }

    /* Getters */
    int day() {
        return d;
    }
    Month month() {
        return m;
    }
    int year() {
        return y;
    }

    /* Overload the << operator to print date & set field width with formatting */
    friend ostream &operator <<(ostream &os, const Date &date) {
        os << setfill('0') << setw(2) << date.d << '-' << setw(2) << date.m << '-'
           << setw(4) << date.y;
        return os;
    }
private:
    int d, y;
    Month m;
    /* Invalid date check using boolean: declaration */
    bool checkDate (int yy, Month mm, int dd);
};

/* Time Class */
class Time {
private:
    int h, m;
    /* Invalid time check using boolean: declaration */
    bool checkHour(int hh, int mm);
public:
    class BadTime { };
    /* Constructor */
    Time(int hh, int mm) : h(hh), m(mm) {
        if(!checkHour(h, m)) {
            throw BadTime();
        }
    }

    /* Getters */
    int hour() {
        return h;
    }
    int minute() {
        return m;
    }

    /* Overload the << operator to print time & set field width with formatting */
    friend ostream &operator <<(ostream &os, const Time &time) {
        os << setfill('0') << setw(2) << time.h << ':' << setw(2) << time.m;
        return os;
    }
};

/* Event Class */
class Event {
private:
    Date date;
    Time start_time, end_time;
    string location;
    vector<string> attendee;
public:
    /* Constructor & intializer */
    Event(Date dte, Time start_t, Time end_t, string lct) : date(dte), start_time(start_t), end_time(end_t), location(lct) {}

    /* Push attendee name into attendee vector */
    void add_attendee(string name) {
        attendee.push_back(name);
    }

    /* Print Event contents (date, time, attendees)
    [in Step 4 final format]*/
    void print() {
        cout << date.year() << '-';
        cout << date.month() << '-';
        cout << date.day() << ' ';

        cout << start_time.hour() << ':';
        cout << start_time.minute() << '0' << '-';
        cout << end_time.hour() << ':';
        cout << end_time.minute() << '0' << " ";

        cout << location << "\n";

        /* Check if attendee vector is not empty before printing out attendees */
        if (!attendee.empty()) {
            for (int i = 0; i < attendee.size(); i++) {
                cout << "attendee: " << attendee[i] << '\n';
            }
        } else {
            cout << "No attendee.\n";
        }
    }

    /* Overload the << operator to print out Event contents */
    friend ostream &operator <<(ostream &os, Event &event) {
        event.print();
        return os;
    }
};

/* Meeting Class */
class Meeting : public Event { // inheritance from Event class
private:
    string chair;
public:
    /* Constructor & intializer */
    Meeting(Date dte, Time start_t, Time end_t, string lct, string chr) : Event(dte, start_t, end_t, lct), chair(chr) {}

    /* Call Event's print and override to add Chair */
    void print() {
        Event::print();
        cout << "Chair: " << chair;
    }

    /* Overload the << operator to print out Meeting contents */
    friend ostream &operator <<(ostream &os, Meeting &meeting) {
        meeting.print();
        return os;
    }
};

/* LOAD function: declaration */
vector<Meeting> load(string file);

} // end of scheduler namespace

#endif // SCHEDULER_H