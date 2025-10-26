#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Book {
private:
    char* title;
    int pages;

public:
    Book(const char* t, int p) : pages(p) {
        title = new char[strlen(t) + 1];
        strcpy_s(title, strlen(t) + 1, t);
    }

    // Constructor de copiere - deep copy
    Book(const Book& other) : pages(other.pages) {
        title = new char[strlen(other.title) + 1];
        strcpy_s(title, strlen(other.title) + 1, other.title);
    }

    ~Book() {
        delete[] title;
    }

    Book& operator=(const Book& other) {
        if (this != &other) {
            delete[] title;
            pages = other.pages;
            title = new char[strlen(other.title) + 1];
            strcpy_s(title, strlen(other.title) + 1, other.title);
        }
        return *this;
    }
    void print() const {
        cout << "Title: " << title << ", Pages: " << pages << endl;
    }
};

int main() {
    Book b1("C++ Programming", 500);
    Book b2 = b1;
    // (dacă am fi avut shallow copy, modificarea în b1 s-ar fi reflectat și în b2)
    b1.print();
    b2.print();
    return 0;
}
