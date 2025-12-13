#include <iostream>
using namespace std;

class Data {
private:
    int zi;
    int luna;
    int an;

    // Funcție pentru a verifica dacă o dată este validă
    bool esteDataValida(int zi, int luna, int an) const {
        if (an < 1 || luna < 1 || luna > 12 || zi < 1) {
            return false;
        }

        // Numărul de zile în fiecare lună
        int zileInLuna[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        // Verificăm dacă anul este bisect
        if (luna == 2 && esteAnBisect(an)) {
            zileInLuna[1] = 29;
        }

        return zi <= zileInLuna[luna - 1];
    }

    // Funcție pentru a verifica dacă un an este bisect
    bool esteAnBisect(int an) const {
        return (an % 4 == 0 && an % 100 != 0) || (an % 400 == 0);
    }

public:
    // Constructor
    Data(int zi = 1, int luna = 1, int an = 2000) {
        if (esteDataValida(zi, luna, an)) {
            this->zi = zi;
            this->luna = luna;
            this->an = an;
        }
        else {
            throw invalid_argument("Data invalida!");
        }
    }

    // Getter pentru zi
    int getZi() const {
        return zi;
    }

    // Setter pentru zi
    void setZi(int ziNou) {
        if (esteDataValida(ziNou, luna, an)) {
            zi = ziNou;
        }
        else {
            throw invalid_argument("Zi invalida!");
        }
    }

    // Getter pentru luna
    int getLuna() const {
        return luna;
    }

    // Setter pentru luna
    void setLuna(int lunaNoua) {
        if (esteDataValida(zi, lunaNoua, an)) {
            luna = lunaNoua;
        }
        else {
            throw invalid_argument("Luna invalida!");
        }
    }

    // Getter pentru an
    int getAn() const {
        return an;
    }

    // Setter pentru an
    void setAn(int anNou) {
        if (esteDataValida(zi, luna, anNou)) {
            an = anNou;
        }
        else {
            throw invalid_argument("An invalid!");
        }
    }

    // Metodă pentru afișarea datei
    void afiseazaData() const {
        cout << (zi < 10 ? "0" : "") << zi << "/"
            << (luna < 10 ? "0" : "") << luna << "/"
            << an << std::endl;
    }
};

int main() {
    try {
        // Creăm un obiect Data
        Data data(29, 2, 2024); // An bisect

        // Afișăm data inițială
        cout << "Data initiala: ";
        data.afiseazaData();

        // Modificăm ziua, luna și anul
        data.setZi(15);
        data.setLuna(12);
        data.setAn(2023);

        // Afișăm data actualizată
        cout << "Data actualizata: ";
        data.afiseazaData();

        // Testare cu o dată invalidă (aruncă excepție)
        cout << "Incerc sa setez o data invalida..." << endl;
        data.setZi(31);
        data.setLuna(2); // Februarie are maxim 29 zile în an bisect
    }
    catch (const std::exception& e) {
        cerr << "Eroare: " << e.what() << endl;
    }

    return 0;
}
