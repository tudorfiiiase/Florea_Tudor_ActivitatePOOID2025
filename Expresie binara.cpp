#include <iostream>
using namespace std;

// Clasa de bază template ExpresieBinara
template <typename T>
class ExpresieBinara {
protected:
    T operand1, operand2;

public:
    ExpresieBinara(T op1, T op2) : operand1(op1), operand2(op2) {}

    // Metodă virtuală pură pentru evaluarea expresiei
    virtual T evalueaza() const = 0;

    // Destructor virtual
    virtual ~ExpresieBinara() = default;
};

// Clasa derivată pentru adunare
template <typename T>
class Adunare : public ExpresieBinara<T> {
public:
    Adunare(T op1, T op2) : ExpresieBinara<T>(op1, op2) {}

    // Implementarea evaluării pentru adunare
    T evalueaza() const override {
        return this->operand1 + this->operand2;
    }
};

// Clasa derivată pentru scădere
template <typename T>
class Scadere : public ExpresieBinara<T> {
public:
    Scadere(T op1, T op2) : ExpresieBinara<T>(op1, op2) {}

    // Implementarea evaluării pentru scădere
    T evalueaza() const override {
        return this->operand1 - this->operand2;
    }
};

// Clasa derivată pentru înmulțire
template <typename T>
class Inmultire : public ExpresieBinara<T> {
public:
    Inmultire(T op1, T op2) : ExpresieBinara<T>(op1, op2) {}

    // Implementarea evaluării pentru înmulțire
    T evalueaza() const override {
        return this->operand1 * this->operand2;
    }
};

// Clasa derivată pentru împărțire
template <typename T>
class Impartire : public ExpresieBinara<T> {
public:
    Impartire(T op1, T op2) : ExpresieBinara<T>(op1, op2) {
        if (op2 == 0) {
            throw invalid_argument("Impartirea la zero nu este permisa.");
        }
    }

    // Implementarea evaluării pentru împărțire
    T evalueaza() const override {
        return this->operand1 / this->operand2;
    }
};

// Funcția template pentru evaluarea unei ExpresiiBinare
template <typename T>
T evalueaza(const ExpresieBinara<T>& expresie) {
    return expresie.evalueaza();
}

int main() {
    try {
        // Creăm expresii pentru diferite operații
        Adunare<int> adunare(10, 5);
        Scadere<int> scadere(10, 5);
        Inmultire<int> inmultire(10, 5);
        Impartire<int> impartire(10, 5);

        // Evaluăm și afișăm rezultatele
        cout << "Adunare: " << evalueaza(adunare) << endl;
        cout << "Scadere: " << evalueaza(scadere) << endl;
        cout << "Inmultire: " << evalueaza(inmultire) << endl;
        cout << "Impartire: " << evalueaza(impartire) << endl;

        // Test cu tipuri reale
        Adunare<double> adunareDouble(10.5, 2.3);
        cout << "Adunare cu double: " << evalueaza(adunareDouble) << endl;

        // Test pentru împărțire la zero
        Impartire<int> impartireZero(10, 0); // Aruncă excepție
        cout << "Impartire: " << evalueaza(impartireZero) << endl;

    }
    catch (const std::exception& e) {
        cerr << "Eroare: " << e.what() << endl;
    }

    return 0;
}
