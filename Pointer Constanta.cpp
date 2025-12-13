#include <iostream>
#include <string>
using namespace std;

int main() {
    int a = 10;
    int b = 20;

    // 1. Pointer la constantă (pointer spre o valoare care nu poate fi modificată prin intermediul acestui pointer)
    const int* p1 = &a;
    p1 = &b;     // Este permis: putem schimba locația spre care pointează p1.

    // 2. Pointer constant (pointer al cărui adresă stocată nu poate fi schimbată, însă valoarea la care pointează poate fi modificată)
    int* const p2 = &a;
    *p2 = 30;    // Este permis: modificăm valoarea la care pointează p2.
    // p2 = &b;

    // 3. Pointer constant la constantă (nici adresa și nici valoarea nu pot fi schimbate):
    const int* const p3 = &a;
    // *p3 = 40;
    // p3 = &b;

    cout << "a = " << a << std::endl;
    cout << "Valoarea la care pointeaza p1: " << *p1 << endl;
    cout << "Valoarea la care pointeaza p2: " << *p2 << endl;
    cout << "Valoarea la care pointeaza p3: " << *p3 << endl;
    return 0;
}
