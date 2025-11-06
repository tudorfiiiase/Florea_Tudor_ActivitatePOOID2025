#include <iostream>
#include <string>
using namespace std;

class Factura {
private:
    int numarFactura;
    float valoare;
    static int contorFacturi;

public:
    static float TVA;
    const string moneda;

    Factura(int numar, float val) : numarFactura(numar), valoare(val), moneda("RON") {
        contorFacturi++;
    }

    float calculeazaTotalCuTVA() const {
        return valoare * (1.0f + TVA);
    }

    void afiseazaDetalii() const {
        cout << "Factura nr. " << numarFactura << endl;
        cout << "Valoare fara TVA: " << valoare << " " << moneda << endl;
        cout << "Valoare cu TVA: " << calculeazaTotalCuTVA() << " " << moneda << endl;
        cout << "--------------------------" << endl;
    }

    static int getNumarFacturi() {
        return contorFacturi;
    }
};

float Factura::TVA = 0.19f;
int Factura::contorFacturi = 0;

int main() {
    Factura f1(1, 500.0f);
    Factura f2(2, 1000.5f);
    Factura f3(3, 2500.0f);
    f1.afiseazaDetalii();
    f2.afiseazaDetalii();
    f3.afiseazaDetalii();
    cout << "Numarul total de facturi emise: " << Factura::getNumarFacturi() << endl;
    return 0;
}
