#include <iostream>
#include <string>
using namespace std;

int main() {
    int x;
    int* p = &x;
    *p = 3;
    cout << "Valoarea lui x: " << x << endl;
    return 0;
}
