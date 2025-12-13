#include <iostream>
using namespace std;

class Laptop {
private:
    int RAM;

public:
    void setRAM(int ram) {
        if (ram >= 2 && ram <= 128)
            RAM = ram;
        else
            cout << "Valoare invalida!" << endl;
        }

    int getRAM() const {
        return RAM;
    }
};

int main() {
    Laptop l1; // implică 8 GB RAM (din constructor)
    cout << "Laptop l1 are " << l1.getRAM() << " GB RAM." << endl;
    l1.setRAM(16);
    cout << "Laptop l1 are acum " << l1.getRAM() << " GB RAM." << endl;
    l1.setRAM(256); // valoare invalida, se va reseta la 8 GB
    cout << "Laptop l1 dupa setare invalida are " << l1.getRAM() << " GB RAM." << endl;
    return 0;
}
