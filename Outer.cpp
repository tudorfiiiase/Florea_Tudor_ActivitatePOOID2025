#include <iostream>
using namespace std;

class Outer {
public:
    // Clasa Nested definită în interiorul clasei Outer
    class Nested {
    private:
        int nestedValue;

    public:
        // Constructor pentru Nested
        Nested(int value) : nestedValue(value) {}

        int getValue() const {
            return nestedValue;
        }
    };

    // Metodă din Outer care accesează un obiect Nested
    void accessNested() {
        Nested nestedObj(42); 
        cout << "Valoarea din Nested este: " << nestedObj.getValue() << endl;
    }
};

int main() {
    Outer outerObj;
    outerObj.accessNested();
    // Alternativ, creăm direct un obiect Nested din Outer
    Outer::Nested directNested(99);
    cout << "Valoarea direct accesata din Nested este: " << directNested.getValue() << endl;
    return 0;
}
