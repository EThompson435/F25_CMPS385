#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Date {
    int day, month, year;
};

struct Appointment {
    int id;
    string name;
    Date date;
    string purpose;
};

Appointment schedule[50];
int countAppointments = 0;

int main() {
    srand(time(0));
    int choice;

    cout << "*********** Appointment Scheduler ***********\n";

    do {
        cout << "\n1. Add a new appointment\n";
        cout << "2. View appointments by date\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            if (countAppointments < 50) {
                Appointment a;
                cin.ignore(); // clear buffer
                cout << "Enter name: ";
                getline(cin, a.name);

                cout << "Enter date (MM/DD/YYYY): ";
                char slash;
                cin >> a.date.month >> slash >> a.date.day >> slash >> a.date.year;
                cin.ignore();

                cout << "Enter purpose: ";
                getline(cin, a.purpose);

                a.id = 1000 + rand() % 9000;
                schedule[countAppointments++] = a;

                cout << "Appointment added! ID: " << a.id << "\n";
            }
            else {
                cout << "No more appointments can be added.\n";
            }
        }
        else if (choice == 2) {
            Date d;
            cout << "Enter date (MM/DD/YYYY): ";
            char slash;
            cin >> d.month >> slash >> d.day >> slash >> d.year;

            bool found = false;
            cout << "ID | Name | Purpose\n";
            for (int i = 0; i < countAppointments; i++) {
                if (schedule[i].date.day == d.day &&
                    schedule[i].date.month == d.month &&
                    schedule[i].date.year == d.year) {
                    cout << schedule[i].id << " | "
                        << schedule[i].name << " | "
                        << schedule[i].purpose << "\n";
                    found = true;
                }
            }
            if (!found) cout << "No appointments for this date.\n";
        }
        else if (choice == 3) {
            cout << "Thank you for using the scheduler!\n";
        }
        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 3);

    return 0;
}
