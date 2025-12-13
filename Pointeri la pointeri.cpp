#include <iostream>
#include <string>
using namespace std;

int main() {

    int x = 10;
    int* p = &x;
    int** pp = &p;

    cout << "Valoarea initiala a lui x: " << x << endl;

    **pp = 20;

    cout << "Valoarea lui x dupa modificare prin pp: " << x << endl;

    return 0;
}
