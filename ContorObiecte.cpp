#include <iostream>
#include <string>
using namespace std;

class ContorObiecte {
private:
    static int numarObiecte;

public:
    ContorObiecte() {
        numarObiecte++;
    }

    static int getNumarObiecte() {
        return numarObiecte;
    }
};

int ContorObiecte::numarObiecte = 0;

int main() {
    ContorObiecte obj1;
    ContorObiecte obj2;
    ContorObiecte obj3;
    ContorObiecte obj4;

    std::cout << "Numarul total de obiecte create: "
        << ContorObiecte::getNumarObiecte() << std::endl;

    return 0;
}
