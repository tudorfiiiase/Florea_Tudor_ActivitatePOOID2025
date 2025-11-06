#include <iostream>
#include <string>
using namespace std;

class Matematica {
public:
    
    static int patrat(int x) {
        return x * x;
    }
    
    static int suma(int a, int b) {
        return a + b;
    }
    
    static int produs(int a, int b) {
        return a * b;
    }
};

int main() {
    
    int x = 10;
    int a = 12, b = 6;
    cout << "Patratul lui " << x << " este: " << Matematica::patrat(x) << endl;
    cout << "Suma lui " << a << " si " << b << " este: " << Matematica::suma(a, b) << endl;
    cout << "Produsul lui " << a << " si " << b << " este: " << Matematica::produs(a, b) << endl;
    return 0;
}
