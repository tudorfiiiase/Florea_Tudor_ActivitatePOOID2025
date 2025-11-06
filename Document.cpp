#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Document {
private:
    char* text;

public:
    
    Document(const char* initialText) {
        text = new char[strlen(initialText) + 1]; 
        strcpy_s(text, strlen(initialText) + 1, initialText);
    }

    // Constructor de copiere (shallow copy)
    Document(const Document& other) {
        // Shallow copy - copiază doar adresa pointerului
        // Deep copy - alocă memorie nouă și copiază conținutul
        text = new char[strlen(other.text) + 1];
        strcpy_s(text, strlen(other.text) + 1, other.text);
    }

    // Destructor
    ~Document() {
        delete[] text;
    }

    void print() const {
        cout << "Text: " << text << endl;
    }
    void setText(const char* newText) {
        delete[] text;
        text = new char[strlen(newText) + 1];
        strcpy_s(text, strlen(newText) + 1, newText);
    }
};

int main() {
    Document doc1("Original Text");
    doc1.print();
    Document doc2 = doc1;
    doc2.print();
    doc1.setText("Modified Text");
    doc1.print();
    doc2.print(); // Aici observăm efectul shallow copy sau deep copy
    return 0;
}
