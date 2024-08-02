#include <bits/stdc++.h>
using namespace std;

class Library {
public:
    void add_user(int roll_no, string name) {
        ofstream my_file;
        my_file.open("users.txt", ios::app); // Open in append mode
        if (my_file.is_open()) {
            my_file << roll_no << " " << name << endl;
            cout << "Registered successfully" << endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }

    void add_book(int book_id, string book_name) {
        ofstream my_file;
        my_file.open("books.txt", ios::app); // Open in append mode
        if (my_file.is_open()) {
            my_file << book_id << " " << book_name << endl;
            cout << "Added successfully" << endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }

    void borrow_book(int roll_no, string name, int book_id, string book_name) {
        ofstream my_file;
        my_file.open("borrowedList.txt", ios::app); // Open in append mode
        if (my_file.is_open()) {
            my_file << roll_no << " " << name << " " << book_id << " " << book_name << endl;
            cout << "Borrowed successfully" << endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }
};

int main() {
    int book_id;
    string book_name;
    int roll_no;
    Library library;
    cout << "*****WELCOME TO LIBRARY*****" << endl;
    cout << "Please select one option " << endl;
    cout << "1. User \n2. Admin" << endl;
    int choice;
    string name;
    cin >> choice;

    if (choice == 1) {
        int desc;
        cout << "Welcome! Please may I know your name:" << endl;
        cin >> name;
        cout << "Welcome " << name << " to our library. Please select one of the given options:" << endl;
        cout << "1. Register\n2. Borrow Book" << endl;
        cin >> desc;

        if (desc == 1) {
            cout << "Would you like to register in our library?" << endl;
            cout << "1. Yes \n2. No" << endl;
            int decision;
            cin >> decision;

            if (decision == 1) {
                cout << "Enter roll no:";
                cin >> roll_no;
                cout << "Enter name:";
                cin >> name;

                ifstream my_file("users.txt"); // Open the file for reading
                string line;
                bool already_registered = false;

                while (getline(my_file, line)) {
                    stringstream ss(line);
                    int registered_rollno;
                    string registered_name;
                    ss >> registered_rollno >> registered_name; // Extract the roll number and name from the line
                    if (registered_rollno == roll_no) {
                        already_registered = true;
                        cout << "The roll no is already taken. Please try again with a correct roll no." << endl;
                        break;
                    }
                }

                if (!already_registered) {
                    library.add_user(roll_no, name);
                }
            }
        } else if (desc == 2) {
            cout << "Enter roll no:";
            cin >> roll_no;
            cout << "Enter name:";
            cin >> name;
            cout << "Enter book ID you want to borrow:";
            cin >> book_id;
            cout << "Enter book name you want to borrow:";
            cin >> book_name;

            library.borrow_book(roll_no, name, book_id, book_name);
        }

    } else if (choice == 2) {
        cout << "Choose any one option below: " << endl;
        cout << "1. Add books \n2. Show student book borrow" << endl;
        int decision;
        cin >> decision;

        if (decision == 1) {
            cout << "Enter ID:";
            cin >> book_id;
            cout << "Enter book name:";
            cin >> book_name;

            ifstream my_file("books.txt"); // Open the file for reading
            string line;
            bool already_present = false;

            while (getline(my_file, line)) {
                stringstream ss(line);
                int registered_bookid;
                string registered_bookname;
                ss >> registered_bookid >> registered_bookname; // Extract the book ID and name from the line
                if (registered_bookid == book_id) {
                    already_present = true;
                    cout << "The book ID is already taken. Please try again with a correct ID." << endl;
                    break;
                }
            }

            if (!already_present) {
                library.add_book(book_id, book_name);
            }
        }
    }

    return 0;
}
