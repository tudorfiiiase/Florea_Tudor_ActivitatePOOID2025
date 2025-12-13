#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

// Definirea clasei template Matrice
template <typename T>
class Matrice {
private:
    vector<vector<T>> elemente;
    size_t randuri;
    size_t coloane;

public:
    // Constructor
    Matrice(size_t randuri, size_t coloane, T valoareInitiala = T())
        : randuri(randuri), coloane(coloane), elemente(randuri, vector<T>(coloane, valoareInitiala)) {}

    // Metoda pentru accesarea elementului (getter)
    T& operator()(size_t i, size_t j) {
        if (i >= randuri || j >= coloane)
            throw out_of_range("Index in afara limitelor matricei.");
        return elemente[i][j];
    }

    // Metoda const pentru accesare (pentru matrice constante)
    const T& operator()(size_t i, size_t j) const {
        if (i >= randuri || j >= coloane)
            throw out_of_range("Index in afara limitelor matricei.");
        return elemente[i][j];
    }

    // Suprasarcinarea operatorului + pentru adunarea matricelor
    Matrice operator+(const Matrice& alt) const {
        if (randuri != alt.randuri || coloane != alt.coloane)
            throw invalid_argument("Dimensiunile matricelor nu coincid pentru adunare.");
        Matrice rezultat(randuri, coloane);
        for (size_t i = 0; i < randuri; ++i) {
            for (size_t j = 0; j < coloane; ++j) {
                rezultat(i, j) = elemente[i][j] + alt.elemente[i][j];
            }
        }
        return rezultat;
    }

    // Suprasarcinarea operatorului * pentru înmulțirea matricelor
    Matrice operator*(const Matrice& alt) const {
        if (coloane != alt.randuri)
            throw invalid_argument("Dimensiunile matricelor nu permit inmultirea.");
        Matrice rezultat(randuri, alt.coloane);
        for (size_t i = 0; i < randuri; ++i) {
            for (size_t j = 0; j < alt.coloane; ++j) {
                T suma = T();
                for (size_t k = 0; k < coloane; ++k) {
                    suma += elemente[i][k] * alt.elemente[k][j];
                }
                rezultat(i, j) = suma;
            }
        }
        return rezultat;
    }

    // Metoda pentru transpunerea unei matrice
    Matrice transpusa() const {
        Matrice rezultat(coloane, randuri);
        for (size_t i = 0; i < randuri; ++i) {
            for (size_t j = 0; j < coloane; ++j) {
                rezultat(j, i) = elemente[i][j];
            }
        }
        return rezultat;
    }

    // Funcția friend pentru afișare
    friend ostream& operator<<(ostream& os, const Matrice& mat) {
        for (const auto& rand : mat.elemente) {
            for (const auto& elem : rand) {
                os << elem << " ";
            }
            os << "\n";
        }
        return os;
    }
};

int main() {
    // Crearea a două matrice de numere întregi
    Matrice<int> mat1(2, 3, 1); // Matrice 2x3 inițializată cu 1
    Matrice<int> mat2(2, 3, 2); // Matrice 2x3 inițializată cu 2

    // Adăugăm valori specifice în matrice
    mat1(0, 0) = 5; mat1(0, 1) = 4; mat1(1, 2) = 3;
    mat2(0, 0) = 1; mat2(1, 1) = 7;

    // Afișăm cele două matrici
    cout << "Matricea 1:\n" << mat1 << endl;
    cout << "Matricea 2:\n" << mat2 << endl;

    // Adunarea matricelor
    Matrice<int> suma = mat1 + mat2;
    cout << "Suma matricelor:\n" << suma << endl;

    // Crearea a două matrici pentru înmulțire
    Matrice<int> mat3(2, 2, 1);
    Matrice<int> mat4(2, 2, 2);
    mat3(0, 1) = 3; mat4(1, 0) = 4;

    // Înmatriculare
    Matrice<int> produs = mat3 * mat4;
    cout << "Produsul matricelor:\n" << produs << endl;

    // Transpunerea unei matrice
    Matrice<int> transpusa = mat1.transpusa();
    cout << "Transpusa Matricei 1:\n" << transpusa << endl;

    return 0;
}
