
#include<bits/stdc++.h>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool available;

    Book(int id, string title, string author)
        : id(id), title(title), author(author), available(true) {}

    void displayDetails() {
        cout << "ID: " << id << ", Title: " << title 
             << ", Author: " << author 
             << ", Available: " << (available ? "Yes" : "No") << endl;
    }
};

class User {
public:
    int id;
    string name;
    vector<int> borrowedBooks;

    User(int id, string name) : id(id), name(name) {}

    void borrowBook(int bookId) {
        borrowedBooks.push_back(bookId);
    }

    void returnBook(int bookId) {
        borrowedBooks.erase(remove(borrowedBooks.begin(), borrowedBooks.end(), bookId), borrowedBooks.end());
    }
};

class Library {
public:
    vector<Book> books;
    vector<User> users;

    void addBook(Book book) {
        books.push_back(book);
    }

    void addUser(User user) {
        users.push_back(user);
    }

    void searchBook(string title) {
    for (size_t i = 0; i < books.size(); ++i) {
        if (books[i].title == title) {
            books[i].displayDetails();
            return;
        }
    }
    cout << "Book not found!" << endl;
}
};

int main() {
    Library library;
    library.addBook(Book(1, "1984", "George Orwell"));
    library.addUser(User(1, "Alice"));

    library.searchBook("1984");

    return 0;
}

