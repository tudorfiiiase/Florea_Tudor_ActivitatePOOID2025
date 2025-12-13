#include <iostream>
#include <string>
using namespace std;

// Clasa de bază abstractă Personaj
class Personaj {
protected:
    string nume;
    int viata;
    int putere;

public:
    // Constructor
    Personaj(const string& nume, int viata, int putere)
        : nume(nume), viata(viata), putere(putere) {}

    // Funcții virtuale pure
    virtual void ataca(Personaj& inamic) = 0;
    virtual void apara(int damage) = 0;

    // Metodă pentru a verifica dacă personajul mai este în viață
    bool esteInViata() const {
        return viata > 0;
    }

    // Destructor virtual
    virtual ~Personaj() {}
};

// Clasa derivată Razboinic
class Razboinic : public Personaj {
public:
    Razboinic(const string& nume)
        : Personaj(nume, 150, 30) {} // Razboinicul are multă viață și putere medie

    void ataca(Personaj& inamic) override {
        cout << nume << " lovește cu sabia și provoacă " << putere
            << " daune!" << endl;
        inamic.apara(putere);
    }

    void apara(int damage) override {
        int damageRedus = damage - 10; // Reduce daunele cu un scut
        if (damageRedus < 0) damageRedus = 0;
        viata -= damageRedus;
        cout << nume << " blochează o parte din atac. Viața rămasă: " << viata << endl;
    }
};

// Clasa derivată Magician
class Magician : public Personaj {
public:
    Magician(const string& nume)
        : Personaj(nume, 100, 50) {} // Magicianul are viață mai mică, dar atac puternic

    void ataca(Personaj& inamic) override {
        cout << nume << " lansează o vrajă de foc și provoacă " << putere
            << " daune!" << endl;
        inamic.apara(putere);
    }

    void apara(int damage) override {
        viata -= damage; // Magicianul nu are mecanisme defensive speciale
        cout << nume << " primește atacul. Viața rămasă: " << viata << endl;
    }
};

// Clasa derivată Arcas
class Arcas : public Personaj {
public:
    Arcas(const string& nume)
        : Personaj(nume, 120, 40) {} // Arcasul are o combinație echilibrată

    void ataca(Personaj& inamic) override {
        cout << nume << " trage o săgeată și provoacă " << putere
            << " daune!" << endl;
        inamic.apara(putere);
    }

    void apara(int damage) override {
        int damageRedus = damage / 2; // Arcasul are agilitate și evită jumătate din daune
        viata -= damageRedus;
        cout << nume << " evită o parte din atac. Viața rămasă: " << viata << endl;
    }
};

// Funcția principală pentru simularea luptei
int main() {
    // Creăm personajele
    Razboinic razboinic("Conan");
    Magician magician("Merlin");
    Arcas arcas("Robin");

    // Simulăm lupta între personajele create
    std::cout << "Lupta începe!" << endl;

    // Runda 1: Conan atacă Merlin
    razboinic.ataca(magician);

    // Runda 2: Merlin atacă Robin
    magician.ataca(arcas);

    // Runda 3: Robin atacă Conan
    arcas.ataca(razboinic);

    // Verificăm dacă personajele mai sunt în viață
    cout << "\nRezultat final:" << endl;
    cout << "Conan: " << (razboinic.esteInViata() ? "În viață" : "Mort") << endl;
    cout << "Merlin: " << (magician.esteInViata() ? "În viață" : "Mort") << endl;
    cout << "Robin: " << (arcas.esteInViata() ? "În viață" : "Mort") << endl;

    return 0;
}
