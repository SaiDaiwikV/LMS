// LMS BY SAIDAIWIK.V

#include <bits/stdc++.h>
using namespace std;

const int MAX_BOOKS = 1000;

struct Book {
    int id;
    string title;
    string author;
    bool available;
};

vector<Book> library;
int numBooks = 0;

// Function to add a new book to the library
void AddNewBook() {
    if (numBooks >= MAX_BOOKS) {
        cout << "The library is at maximum capacity. Cannot add more books." << endl;
        return;
    }

    Book newBook;
    newBook.id = numBooks + 1;  // Assign a unique ID to the new book starting from 1
    cout << "Enter the title of the new book: ";
    cin.ignore();
    getline(cin, newBook.title);
    cout << "Enter the author of the new book: ";
    getline(cin, newBook.author);
    newBook.available = true;
    library.push_back(newBook);
    numBooks++;
    cout << "The book has been successfully added!" << endl;
}

// Function to search for a book by title and author
void SearchForBook() {
    cout << "Please enter the title of the book: ";
    string bookTitle;
    cin.ignore();
    getline(cin, bookTitle);
    cout << "Please enter the author of the book: ";
    string bookAuthor;
    getline(cin, bookAuthor);

    for (const auto& book : library) {
        if (book.title == bookTitle && book.author == bookAuthor) {
            cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author
                 << ", Available: " << (book.available ? "Yes" : "No") << endl;
            return;
        }
    }

    cout << "No book found with the title: " << bookTitle << " and author: " << bookAuthor << endl;
}

// Function to return a book
void ReturnABook() {
    int bookID;
    cout << "Enter the ID of the book to be returned: ";
    cin >> bookID;

    for (auto& book : library) {
        if (book.id == bookID && !book.available) {
            book.available = true;
            cout << "The book has been successfully returned!" << endl;
            return;
        }
    }

    cout << "The book is not currently issued." << endl;
}

// Function to list all the books in the library
void ListAllBooks() {
    if (library.empty()) {
        cout << "The library is currently empty." << endl;
        return;
    }

    sort(library.begin(), library.end(), [](const Book& a, const Book& b) {
        return a.title < b.title;
    });

    cout << "List of all books in the library (sorted by title):" << endl;
    for (const auto& book : library) {
        cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author
             << ", Available: " << (book.available ? "Yes" : "No") << endl;
    }
}

// Function to delete a book from the library
void DeleteABook() {
    int bookID;
    cout << "Enter the ID of the book to be deleted: ";
    cin >> bookID;

    auto it = find_if(library.begin(), library.end(), [bookID](const Book& book) {
        return book.id == bookID;
    });

    if (it != library.end()) {
        library.erase(it);
        numBooks--;
        cout << "The book has been successfully deleted!" << endl;
    } else {
        cout << "The book does not exist in the library." << endl;
    }
}

// Function to issue a book
void IssueABook() {
    int bookID;
    cout << "Enter the ID of the book to be issued: ";
    cin >> bookID;

    for (auto& book : library) {
        if (book.id == bookID && book.available) {
            book.available = false;
            cout << "The book has been successfully issued!" << endl;
            return;
        }
    }

    cout << "The book is not available for issue." << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "Library Management System by V. Sai Daiwik" << endl;
        cout << "\nLibrary Management System Menu:" << endl;
        cout << "1. Add New Book" << endl;
        cout << "2. Search for a Book" << endl;
        cout << "3. Issue a Book" << endl;
        cout << "4. Return a Book" << endl;
        cout << "5. List All Books" << endl;
        cout << "6. Delete a Book" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: AddNewBook(); break;
            case 2: SearchForBook(); break;
            case 3: IssueABook(); break;
            case 4: ReturnABook(); break;
            case 5: ListAllBooks(); break;
            case 6: DeleteABook(); break;
            case 0: cout << "Program is terminating" << endl; return 0;
            default: cout << "Invalid input. Please enter a valid choice." << endl;
        }
    }

   
    
    return 0;
}
