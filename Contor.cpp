#include <iostream>
#include <string>
using namespace std;

class Contor {
private:
    static int numarObiecte;

public:
    Contor() {
        numarObiecte++;
    }

    static int getNumarObiecte() {
        return numarObiecte;
    }
};

int Contor::numarObiecte = 0;

int main() {
    Contor c1;
    Contor c2;
    Contor c3;
    Contor c4;
    Contor c5;
    cout << "Numarul total de obiecte create: " << Contor::getNumarObiecte() << endl;
    Contor c6;
    cout << "Numarul total de obiecte create dupa c4: " << Contor::getNumarObiecte() << endl;
    return 0;
}
