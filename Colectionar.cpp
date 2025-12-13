#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Clasa template Colectionar
template <typename T>
class Colectionar {
private:
    vector<T> elemente; // Vector pentru a stoca elementele

public:
    // Adaugarea unui element in colectie
    void adauga(const T& element) {
        elemente.push_back(element);
    }

    // Obtinerea tuturor elementelor
    const vector<T>& obtineElemente() const {
        return elemente;
    }

    // Afisarea elementelor colectiei
    void afiseaza() const {
        cout << "Colectie: ";
        for (const auto& elem : elemente) {
            cout << elem << " ";
        }
        cout << endl;
    }
};

// Functie template pentru a gasi duplicatele intr-un Colectionar
template <typename T>
vector<T> gasesteDuplicate(const Colectionar<T>& colectie) {
    unordered_map<T, int> frecventa;
    vector<T> duplicate;

    // Calculam frecventa fiecarui element
    for (const auto& elem : colectie.obtineElemente()) {
        frecventa[elem]++;
    }

    // Adaugam in vector doar elementele care apar de mai multe ori
    for (const auto& elem : frecventa) {
        if (elem.second > 1) {
            duplicate.push_back(elem.first);
        }
    }

    return duplicate;
}

int main() {
    // Cream un Colectionar de intregi
    Colectionar<int> colectieInt;
    colectieInt.adauga(1);
    colectieInt.adauga(2);
    colectieInt.adauga(3);
    colectieInt.adauga(2);
    colectieInt.adauga(4);
    colectieInt.adauga(3);
    colectieInt.adauga(3);

    // Afisam colectia
    colectieInt.afiseaza();

    // Gasim duplicatele
    auto duplicateInt = gasesteDuplicate(colectieInt);
    cout << "Duplicate: ";
    for (const auto& elem : duplicateInt) {
        cout << elem << " ";
    }
    cout << endl;

    // Cream un Colectionar de string-uri
    Colectionar<string> colectieString;
    colectieString.adauga("Alpha");
    colectieString.adauga("Beta");
    colectieString.adauga("Alpha");
    colectieString.adauga("Gamma");
    colectieString.adauga("Beta");

    // Afisam colectia
    colectieString.afiseaza();

    // Gasim duplicatele
    auto duplicateString = gasesteDuplicate(colectieString);
    cout << "Duplicate: ";
    for (const auto& elem : duplicateString) {
        cout << elem << " ";
    }
    cout << endl;
}