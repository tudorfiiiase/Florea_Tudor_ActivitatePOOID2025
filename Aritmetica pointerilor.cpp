#include <iostream>
#include <string>
using namespace std;

int main() {
    int v[] = { 1, 2, 3, 4, 5 };
    int* p = v;
    int lungime = sizeof(v) / sizeof(v[0]);
    int suma = 0;

    for (int i = 0; i < lungime; i++) {
        suma += *(p + i);
    }

    cout << "Suma elementelor vectorului este: " << suma << endl;
    return 0;
}