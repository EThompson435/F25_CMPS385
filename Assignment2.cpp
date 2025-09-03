#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    int year;
    bool available;

public:
    // Default constructor
    Book() : id(0), title(""), author(""), year(0), available(true) {}

    // Parameterized constructor
    Book(int id, string title, string author, int year)
        : id(id), title(title), author(author), year(year), available(true) {
    }

    // Getters
    int getID() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }
    bool isAvailable() const { return available; }

    // Setters
    void setID(int newID) { id = newID; }
    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setYear(int y) { year = y; }
    void setAvailable(bool avail) { available = avail; }

    // Borrow a book
    void borrowBook() {
        if (available) {
            available = false;
            cout << "You have successfully borrowed '" << title << "'.\n";
        }
        else {
            cout << "Sorry, this book is currently not available.\n";
        }
    }

    // Return a book
    void returnBook() {
        if (!available) {
            available = true;
            cout << "You have successfully returned '" << title << "'.\n";
        }
        else {
            cout << "Book was not borrowed.\n";
        }
    }

    // Display book details
    void display() const {
        cout << "ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
        cout << "Status: " << (available ? "Available" : "Borrowed") << endl;
    }

    // Display summary for listing
    void displaySummary() const {
        cout << "ID: " << id << " | "
            << "Title: " << title << " | "
            << "Author: " << author << " | "
            << "Year: " << year << endl;
    }
};

// Global variables
Book library[100];
int countBooks = 0;

// Generate unique book ID
int generateBookID() {
    int id;
    bool unique;
    do {
        id = 10000 + rand() % 90000; // random 5-digit
        unique = true;
        for (int i = 0; i < countBooks; i++) {
            if (library[i].getID() == id) {
                unique = false;
                break;
            }
        }
    } while (!unique);
    return id;
}

// Find book by ID
int findBook(int id) {
    for (int i = 0; i < countBooks; i++) {
        if (library[i].getID() == id) return i;
    }
    return -1;
}

// Menu option 1: Add new book
void addBook() {
    if (countBooks >= 100) {
        cout << "Library is full!\n";
        return;
    }
    string title, author;
    int year;
    cout << "Enter title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter author: ";
    getline(cin, author);
    cout << "Enter year: ";
    cin >> year;

    int id = generateBookID();
    Book b(id, title, author, year);
    library[countBooks++] = b;

    cout << "Book added successfully!\n";
    cout << "Title: " << title << endl;
    cout << "ID: " << id << endl;
    cout << "Press any key to return to Main Menu!\n";
    cin.ignore(); cin.get();
}

// Menu option 2: Borrow a book
void borrowBook() {
    int id;
    cout << "Enter Book ID: ";
    cin >> id;
    int idx = findBook(id);
    if (idx == -1) {
        cout << "Book not found.\n";
    }
    else {
        library[idx].borrowBook();
    }
    cout << "Press any key to return to Main Menu!\n";
    cin.ignore(); cin.get();
}

// Menu option 3: Return a book
void returnBook() {
    int id;
    cout << "Enter Book ID: ";
    cin >> id;
    int idx = findBook(id);
    if (idx == -1) {
        cout << "Book not found.\n";
    }
    else {
        library[idx].returnBook();
    }
    cout << "Press any key to return to Main Menu!\n";
    cin.ignore(); cin.get();
}

// Menu option 4: Display book details
void displayBook() {
    int id;
    cout << "Enter Book ID: ";
    cin >> id;
    int idx = findBook(id);
    if (idx == -1) {
        cout << "Book not found.\n";
    }
    else {
        library[idx].display();
    }
    cout << "Press any key to return to Main Menu!\n";
    cin.ignore(); cin.get();
}

// Menu option 5: List all available books
void listAvailableBooks() {
    bool any = false;
    cout << "Available Books:\n";
    for (int i = 0; i < countBooks; i++) {
        if (library[i].isAvailable()) {
            library[i].displaySummary();
            any = true;
        }
    }
    if (!any) {
        cout << "No books available at the moment.\n";
    }
    cout << "Press any key to return to Main Menu!\n";
    cin.ignore(); cin.get();
}

int main() {
    srand(time(0));
    int choice;
    do {
        cout << "\n*************** Welcome to the Library ***************\n";
        cout << "Please choose one of the following operations:\n";
        cout << "1 - Add a new book\n";
        cout << "2 - Borrow a book\n";
        cout << "3 - Return a book\n";
        cout << "4 - Display details of a book (by ID)\n";
        cout << "5 - List all available books\n";
        cout << "0 - Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addBook(); break;
        case 2: borrowBook(); break;
        case 3: returnBook(); break;
        case 4: displayBook(); break;
        case 5: listAvailableBooks(); break;
        case 0: cout << "Thank you for using the Library System! Goodbye!\n"; break;
        default: cout << "Invalid choice.\n"; break;
        }
    } while (choice != 0);

    return 0;
}
