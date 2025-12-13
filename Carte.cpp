#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

// Clasa Carte
class Carte {
private:
    string titlu;
    string autor;
    string isbn;
    int anPublicare;
    int exemplareDisponibile;

public:
    Carte(const string& t, const string& a, const string& i, int an, int exemplare)
        : titlu(t), autor(a), isbn(i), anPublicare(an), exemplareDisponibile(exemplare) {}

    // Getters
    string getISBN() const { return isbn; }
    int getExemplareDisponibile() const { return exemplareDisponibile; }

    // Setters
    void setExemplareDisponibile(int exemplare) { exemplareDisponibile = exemplare; }

    // Afișare informații carte
    void afiseazaDetalii() const {
        cout << left << setw(20) << titlu << setw(20) << autor << setw(15) << isbn << setw(10) << anPublicare << setw(10) << exemplareDisponibile << endl;
    }

    // Scriere/citire în/din fișier binar
    void scrieInFisier(ofstream& out) const {
        size_t sizeTitlu = titlu.size();
        size_t sizeAutor = autor.size();
        size_t sizeISBN = isbn.size();

        out.write(reinterpret_cast<const char*>(&sizeTitlu), sizeof(sizeTitlu));
        out.write(titlu.c_str(), sizeTitlu);
        out.write(reinterpret_cast<const char*>(&sizeAutor), sizeof(sizeAutor));
        out.write(autor.c_str(), sizeAutor);
        out.write(reinterpret_cast<const char*>(&sizeISBN), sizeof(sizeISBN));
        out.write(isbn.c_str(), sizeISBN);
        out.write(reinterpret_cast<const char*>(&anPublicare), sizeof(anPublicare));
        out.write(reinterpret_cast<const char*>(&exemplareDisponibile), sizeof(exemplareDisponibile));
    }

    void citesteDinFisier(ifstream& in) {
        size_t sizeTitlu, sizeAutor, sizeISBN;

        in.read(reinterpret_cast<char*>(&sizeTitlu), sizeof(sizeTitlu));
        titlu.resize(sizeTitlu);
        in.read(&titlu[0], sizeTitlu);

        in.read(reinterpret_cast<char*>(&sizeAutor), sizeof(sizeAutor));
        autor.resize(sizeAutor);
        in.read(&autor[0], sizeAutor);

        in.read(reinterpret_cast<char*>(&sizeISBN), sizeof(sizeISBN));
        isbn.resize(sizeISBN);
        in.read(&isbn[0], sizeISBN);

        in.read(reinterpret_cast<char*>(&anPublicare), sizeof(anPublicare));
        in.read(reinterpret_cast<char*>(&exemplareDisponibile), sizeof(exemplareDisponibile));
    }
};

// Funcționalitatea principală
class Biblioteca {
private:
    vector<Carte> carti;
    const string fisierBinar = "carti.dat";
    const string jurnal = "jurnal.txt";

    // Salvare jurnal
    void salveazaInJurnal(const string& mesaj) const {
        ofstream out(jurnal, ios::app);
        if (out) {
            out << mesaj << endl;
        }
    }

public:
    // Citirea cărților din fișierul binar
    void citesteDinFisierBinar() {
        ifstream in(fisierBinar, ios::binary);
        if (in) {
            while (in.peek() != EOF) {
                Carte carte("", "", "", 0, 0);
                carte.citesteDinFisier(in);
                carti.push_back(carte);
            }
        }
    }

    // Salvarea cărților în fișierul binar
    void salveazaInFisierBinar() const {
        ofstream out(fisierBinar, ios::binary);
        if (out) {
            for (const auto& carte : carti) {
                carte.scrieInFisier(out);
            }
        }
    }

    // Adăugare carte
    void adaugaCarte(const Carte& carte) {
        carti.push_back(carte);
        salveazaInJurnal("Adaugata: " + carte.getISBN());
    }

    // Afișare cărți
    void afiseazaCarti() const {
        cout << left << setw(20) << "Titlu" << setw(20) << "Autor" << setw(15) << "ISBN" << setw(10) << "An" << setw(10) << "Exemplare" << endl;
        cout << string(75, '-') << endl;

        for (const auto& carte : carti) {
            carte.afiseazaDetalii();
        }
    }

    // Căutare carte după ISBN
    Carte* cautaCarte(const string& isbn) {
        for (auto& carte : carti) {
            if (carte.getISBN() == isbn) {
                return &carte;
            }
        }
        return nullptr;
    }

    // Ștergere carte
    void stergeCarte(const string& isbn) {
        auto it = std::remove_if(carti.begin(), carti.end(),
            [&isbn](const Carte& carte) { return carte.getISBN() == isbn; });
        if (it != carti.end()) {
            carti.erase(it, carti.end());
            salveazaInJurnal("Stearsa: " + isbn);
        }
    }
};

// Meniu interactiv
void meniu(Biblioteca& biblioteca) {
    int optiune;
    do {
        cout << "\nMeniu Biblioteca:\n";
        cout << "1. Adauga carte\n";
        cout << "2. Afiseaza toate cartile\n";
        cout << "3. Cauta carte dupa ISBN\n";
        cout << "4. Actualizeaza numar de exemplare\n";
        cout << "5. Sterge carte\n";
        cout << "6. Salveaza si iesi\n";
        cout << "Optiune: ";
        cin >> optiune;

        if (optiune == 1) {
            cin.ignore();
            string titlu, autor, isbn;
            int an, exemplare;
            cout << "Titlu: ";
            getline(cin, titlu);
            cout << "Autor: ";
            getline(cin, autor);
            cout << "ISBN: ";
            getline(cin, isbn);
            cout << "An publicare: ";
            cin >> an;
            cout << "Exemplare: ";
            cin >> exemplare;
            biblioteca.adaugaCarte(Carte(titlu, autor, isbn, an, exemplare));
        }
        else if (optiune == 2) {
            biblioteca.afiseazaCarti();
        }
        else if (optiune == 3) {
            cin.ignore();
            string isbn;
            cout << "ISBN: ";
            getline(cin, isbn);
            Carte* carte = biblioteca.cautaCarte(isbn);
            if (carte) {
                carte->afiseazaDetalii();
            }
            else {
                cout << "Cartea nu a fost gasita.\n";
            }
        }
        else if (optiune == 4) {
            cin.ignore();
            string isbn;
            int exemplare;
            cout << "ISBN: ";
            getline(std::cin, isbn);
            Carte* carte = biblioteca.cautaCarte(isbn);
            if (carte) {
                cout << "Exemplare noi: ";
                cin >> exemplare;
                carte->setExemplareDisponibile(exemplare);
                cout << "Numar de exemplare actualizat.\n";
            }
            else {
                cout << "Cartea nu a fost gasita.\n";
            }
        }
        else if (optiune == 5) {
            cin.ignore();
            string isbn;
            cout << "ISBN: ";
            getline(cin, isbn);
            biblioteca.stergeCarte(isbn);
        }
        else if (optiune == 6) {
            biblioteca.salveazaInFisierBinar();
            cout << "Datele au fost salvate. Iesire.\n";
        }
        else {
            cout << "Optiune invalida.\n";
        }
    } while (optiune != 6);
}

int main() {
    Biblioteca biblioteca;
    biblioteca.citesteDinFisierBinar();
    meniu(biblioteca);
    return 0;
}
