#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class Carte {
private:
    string titlu;
    string autor;
    int anPublicatie;

public:
    Carte(const string& titluCarte, const string& autorCarte, int an)
        : titlu(titluCarte), autor(autorCarte), anPublicatie(an) {}

    string getTitlu() const {
        return titlu;
    }

    string getAutor() const {
        return autor;
    }

    int getAnPublicatie() const {
        return anPublicatie;
    }

    void afiseaza() const {
        cout << "Titlu: " << titlu << ", Autor: " << autor << ", An Publicatie: " << anPublicatie << endl;
    }
};

class Biblioteca {
private:
    vector<Carte*> carti; // Vector de pointeri la obiecte Carte

public:
    // Adăugare carte
    void adaugaCarte(const string& titlu, const string& autor, int an) {
        carti.push_back(new Carte(titlu, autor, an));
    }

    // Ștergere carte după titlu
    void stergeCarte(const string& titlu) {
        for (auto it = carti.begin(); it != carti.end(); ++it) {
            if ((*it)->getTitlu() == titlu) {
                delete* it; // Dezalocăm memoria
                carti.erase(it); // Ștergem pointerul din vector
                cout << "Cartea \"" << titlu << "\" a fost stearsa." << endl;
                return;
            }
        }
        cout << "Cartea \"" << titlu << "\" nu a fost gasita." << endl;
    }

    // Afișarea tuturor cărților
    void afiseazaCarti() const {
        if (carti.empty()) {
            cout << "Biblioteca este goala." << endl;
            return;
        }
        for (const auto& carte : carti) {
            carte->afiseaza();
        }
    }

    // Găsirea celei mai vechi cărți
    Carte* ceaMaiVecheCarte() const {
        if (carti.empty()) {
            return nullptr;
        }
        Carte* ceaMaiVeche = carti[0];
        for (const auto& carte : carti) {
            if (carte->getAnPublicatie() < ceaMaiVeche->getAnPublicatie()) {
                ceaMaiVeche = carte;
            }
        }
        return ceaMaiVeche;
    }

    ~Biblioteca() {
        for (auto& carte : carti) {
            delete carte;
        }
    }
};

int main() {
    Biblioteca biblioteca;

    // Adăugăm cărți
    biblioteca.adaugaCarte("1984", "George Orwell", 1949);
    biblioteca.adaugaCarte("Mândrie și prejudecată", "Jane Austen", 1813);
    biblioteca.adaugaCarte("Crimă și pedeapsă", "Fyodor Dostoevsky", 1866);
    biblioteca.adaugaCarte("Alchimistul", "Paulo Coelho", 1988);
    biblioteca.adaugaCarte("O mie de splendide sori", "Khaled Hosseini", 2007);

    // Afișăm toate cărțile
    cout << "Toate cartile din biblioteca:" << endl;
    biblioteca.afiseazaCarti();

    // Ștergem o carte
    cout << "\nStergem cartea \"1984\":" << endl;
    biblioteca.stergeCarte("1984");

    // Afișăm toate cărțile după ștergere
    cout << "\nCartile ramase in biblioteca:" << endl;
    biblioteca.afiseazaCarti();

    // Găsim și afișăm cea mai veche carte
    Carte* vecheCarte = biblioteca.ceaMaiVecheCarte();
    if (vecheCarte) {
        cout << "\nCea mai veche carte din biblioteca:" << endl;
        vecheCarte->afiseaza();
    }
    else {
        cout << "Biblioteca este goala." << endl;
    }

    return 0;
}
