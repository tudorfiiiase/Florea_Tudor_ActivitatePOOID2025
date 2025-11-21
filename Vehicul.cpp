#include <iostream>
#include <string>
using namespace std;

class Vehicul {
private:
    string marca;
    int vitezaMaxima;

public:
    
    Vehicul() : marca("Necunoscuta"), vitezaMaxima(0) {
        cout << "Constructor implicit apelat.\n";
    }

    Vehicul(const std::string& marca, int vitezaMaxima)
        : marca(marca), vitezaMaxima(vitezaMaxima) {
        cout << "Constructor cu parametri apelat.\n";
    }

    Vehicul(const Vehicul& altVehicul)
        : marca(altVehicul.marca), vitezaMaxima(altVehicul.vitezaMaxima) {
        cout << "Constructor de copiere apelat.\n";
    }

    void afiseazaDate() const {
        cout << "Marca: " << marca << ", Viteza maxima: " << vitezaMaxima << " km/h\n";
    }
};

int main() {

    Vehicul v1;
    v1.afiseazaDate();
    Vehicul v2("Mercedes", 200);
    v2.afiseazaDate();
    Vehicul v3 = v2;
    v3.afiseazaDate();

    return 0;
}
