#include <iostream>
#include <string>
using namespace std;

class Produs {
private:
    std::string nume;
    float pret;
    static float TVA;

public:
    Produs() : nume(""), pret(0.0f) {
       
    }

    Produs(const std::string& nume, float pret) : nume(nume), pret(pret) {
       
    }

    Produs(const std::string& nume = "Necunoscut", float pret = 0.0f, float tvaDummy = TVA)
        : nume(nume), pret(pret) {
       
    }

    void afiseazaDate() const {
        std::cout << "Nume: " << nume << std::endl;
        std::cout << "Pret fara TVA: " << pret << std::endl;
        std::cout << "Pret cu TVA: " << pret * (1 + TVA) << std::endl;
    }
};

float Produs::TVA = 0.19f; 

int main() {
    Produs p1;
    p1.afiseazaDate();

    std::cout << "-----------------" << std::endl;

    Produs p2("Laptop", 3000.0f);
    p2.afiseazaDate();

    std::cout << "-----------------" << std::endl;

    Produs p3("Carte", 50.0f);
    p3.afiseazaDate();

    std::cout << "-----------------" << std::endl;

    Produs p4;
    p4.afiseazaDate();

    return 0;
}
