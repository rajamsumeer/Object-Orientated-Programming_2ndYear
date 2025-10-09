/*
Student ID:
Student Name: Raja M. Sumeer
Module: Object Orientated Programming @ Year 2, Semester 2 (Technological University Dublin)

CA03 - Events & Meetings
harness.cpp - test file

Last modified: 31/03/2025 @01:32
*/
#include "scheduler.h"
using namespace scheduler;
#include <iostream>

using namespace std;

int main() {
    try {
        /* Date & Time Class Test*/
        Date d(2024, Date::mar, 12);
        Time t1(15, 0);
        Time t2(16, 0);
        cout << "Date and Time Test:\n";
        cout << d << "\n" << t1 << '-' << t2 << "\n\n";

        /* Event Class Test */
        Event e(d, t1, t2, "Boardroom A");
        e.add_attendee("Dovydas Klisys");
        e.add_attendee("Nicki Mardari");
        e.add_attendee("Joseph Oddi");
        e.add_attendee("Russel Makani");

        cout << "Event Test:\n";
        cout << e << "\n\n";

        /* Meeting Class Test */
        Meeting m(d, t1, t2, "Boardroom A", "Patti Higgins");
        m.add_attendee("Leighton Washington");
        m.add_attendee("Zavier Austin");
        m.add_attendee("Alexis Massey");

        cout << "Meeting Test:\n";
        cout << m << "\n\n";

        /* Load Function Test */
        cout << "Load Test:\n";
        vector<Meeting> mt = load("schedule_5meetings.txt");

        // Print Meeting contents if not empty
        if (!mt.empty()) {
            for (unsigned i = 0; i < mt.size(); i++) {
                cout << mt[i] << "\n\n";
            }
        } else {
            cerr << "Oops! the file is empty?\n";
        }

        /* Edge-condition Checks */
        Date dcheck(2020, Date::mar, 12);
        Time tcheck(15, 65);

    } catch (Date::Bad_Date) {
        cerr << "Oops! Bad date!\n";
    } catch (Time::BadTime) {
        cerr << "Oops! Bad time!\n";
    }
    return 0;
}
