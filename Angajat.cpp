#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Clasa de bază Angajat
class Angajat {
protected:
    string nume;
    int id;
    double salariuDeBaza;

public:
    Angajat(const string& n, int i, double sal) : nume(n), id(i), salariuDeBaza(sal) {}

    virtual double calculeazaSalariu() const = 0;
    virtual void afiseazaDetalii() const = 0;

    virtual ~Angajat() {}
};

// Clasa derivată Manager
class Manager : virtual public Angajat {
private:
    double bonus;

public:
    Manager(const string& n, int i, double sal, double b) : Angajat(n, i, sal), bonus(b) {}

    double calculeazaSalariu() const override {
        return salariuDeBaza + bonus;
    }

    void afiseazaDetalii() const override {
        cout << "Manager: " << nume << ", ID: " << id << ", Salariu: " << calculeazaSalariu() << endl;
    }
};

// Clasa derivată Programator
class Programator : virtual public Angajat {
private:
    int oreSuplimentare;
    double rataOrara;

public:
    Programator(const string& n, int i, double sal, int ore, double rata)
        : Angajat(n, i, sal), oreSuplimentare(ore), rataOrara(rata) {}

    double calculeazaSalariu() const override {
        return salariuDeBaza + oreSuplimentare * rataOrara;
    }

    void afiseazaDetalii() const override {
        cout << "Programator: " << nume << ", ID: " << id << ", Salariu: " << calculeazaSalariu() << endl;
    }
};

// Clasa derivată Vanzator
class Vanzator : public Angajat {
private:
    double procentVanzari;
    double vanzariTotale;

public:
    Vanzator(const string& n, int i, double sal, double procent, double vanzari)
        : Angajat(n, i, sal), procentVanzari(procent), vanzariTotale(vanzari) {}

    double calculeazaSalariu() const override {
        return salariuDeBaza + (procentVanzari * vanzariTotale);
    }

    void afiseazaDetalii() const override {
        cout << "Vanzator: " << nume << ", ID: " << id << ", Salariu: " << calculeazaSalariu() << endl;
    }
};

// Clasa Departament
class Departament {
private:
    vector<Angajat*> angajati;

public:
    ~Departament() {
        for (auto angajat : angajati) {
            delete angajat;
        }
    }

    void adaugaAngajat(Angajat* angajat) {
        angajati.push_back(angajat);
    }

    void eliminaAngajat(int id) {
        for (auto it = angajati.begin(); it != angajati.end(); ++it) {
            if ((*it)->calculeazaSalariu() == id) {
                delete* it;
                angajati.erase(it);
                break;
            }
        }
    }

    void afiseazaSalarii() const {
        std::cout << "Salarii angajati:" << std::endl;
        for (const auto& angajat : angajati) {
            angajat->afiseazaDetalii();
        }
    }
};

// Moștenire multiplă: ManagerIT
class ManagerIT : public Manager, public Programator {
public:
    ManagerIT(const std::string& n, int i, double sal, double b, int ore, double rata)
        : Angajat(n, i, sal), Manager(n, i, sal, b), Programator(n, i, sal, ore, rata) {}

    double calculeazaSalariu() const override {
        return Manager::calculeazaSalariu() + Programator::calculeazaSalariu() - salariuDeBaza;
    }

    void afiseazaDetalii() const override {
        std::cout << "Manager IT: " << nume << ", ID: " << id << ", Salariu: " << calculeazaSalariu() << std::endl;
    }
};

int main() {
    Departament departament;

    departament.adaugaAngajat(new Manager("Ion Popescu", 101, 5000.0, 1000.0));
    departament.adaugaAngajat(new Programator("Ana Ionescu", 102, 4000.0, 20, 50.0));
    departament.adaugaAngajat(new Vanzator("George Georgescu", 103, 3000.0, 0.1, 20000.0));
    departament.adaugaAngajat(new ManagerIT("Maria Vasile", 104, 6000.0, 2000.0, 10, 100.0));

    departament.afiseazaSalarii();
}
