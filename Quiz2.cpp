#include <iostream>
#include <string>
using namespace std;

class Task {
private:
    int id;
    string description;
    bool done;

public:
    Task() : id(0), description(""), done(false) {}
    Task(int tid, string desc) : id(tid), description(desc), done(false) {}

    int getId() const { return id; }
    string getDescription() const { return description; }
    bool isDone() const { return done; }

    void toggle() { done = !done; }

    void display() const {
        cout << "ID: " << id << " | \"" << description << "\" | Status: "
            << (done ? "Done" : "Pending") << endl;
    }
};

int main() {
    const int MAX_TASKS = 50;
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int nextId = 1;
    int choice;

    cout << "*********** Welcome to To-Do Manager ***********" << endl;

    do {
        cout << "1 - Add task\n";
        cout << "2 - Toggle task (by ID)\n";
        cout << "3 - List pending tasks\n";
        cout << "0 - Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore(); // flush newline from buffer

        if (choice == 1) {
            if (taskCount >= MAX_TASKS) {
                cout << "Task limit reached!" << endl;
                continue;
            }
            string desc;
            cout << "Enter description: ";
            getline(cin, desc);
            tasks[taskCount] = Task(nextId, desc);
            cout << "Task added! ID: " << nextId << endl;
            nextId++;
            taskCount++;
        }
        else if (choice == 2) {
            int searchId;
            cout << "Enter Task ID: ";
            cin >> searchId;
            bool found = false;
            for (int i = 0; i < taskCount; ++i) {
                if (tasks[i].getId() == searchId) {
                    tasks[i].toggle();
                    cout << "Toggled task " << searchId << "." << endl;
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Task not found." << endl;
        }
        else if (choice == 3) {
            bool hasPending = false;
            for (int i = 0; i < taskCount; ++i) {
                if (!tasks[i].isDone()) {
                    tasks[i].display();
                    hasPending = true;
                }
            }
            if (!hasPending)
                cout << "No pending tasks." << endl;
        }
        else if (choice == 0) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
