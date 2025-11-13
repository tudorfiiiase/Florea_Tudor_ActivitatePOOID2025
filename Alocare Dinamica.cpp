#include <iostream>
#include <string>
using namespace std;

int main() {

    int* v = new int[10];

    for (int i = 0; i < 10; i++) {
        v[i] = rand() % 100;
    }

    int suma = 0;
    for (int i = 0; i < 10; i++) {
        suma += v[i];
    }

    cout << "Vector: ";
    for (int i = 0; i < 10; i++) {
        cout << v[i] << " ";
    }
    cout << "\nSuma elementelor: " << suma << endl;

    delete[] v;

    return 0;
}
