#include <iostream>
#include <string>
using namespace std;

typedef float (*Operatie)(float, float);

float adunare(float a, float b) {
    return a + b;
}

float scadere(float a, float b) {
    return a - b;
}

float inmultire(float a, float b) {
    return a * b;
}

float impartire(float a, float b) {
    if (b == 0) {
        cerr << "Eroare: Împărțire la zero!" << endl;
        return 0.0f;
    }
    return a / b;
}

int main() {
    float (*pf[])(float, float) = { adunare, scadere, inmultire, impartire };
    int optiune, a, b;
    float x, y;
    Operatie op = nullptr; // Pointerul la funcția care va fi selectată

    while (true) {
        cout << "\nMeniu:\n";
        cout << "1. Adunare\n";
        cout << "2. Scadere\n";
        cout << "3. Inmultire\n";
        cout << "4. Impartire\n";
        cout << "5. Iesire\n";
        cout << "Alege o optiune: ";
        cin >> optiune;

        if (optiune == 5) {
            cout << "La revedere!\n";
            break;
        }

        cout << "Introdu doua numere: ";
        cin >> x >> y;

        switch (optiune) {
        case 1: op = adunare; break;
        case 2: op = scadere; break;
        case 3: op = inmultire; break;
        case 4: op = impartire; break;
        default:
            cout << "Optiune invalida!\n";
            continue; // Revine la afișarea meniului
        }

        // Apelăm funcția prin intermediul pointerului
        if (op) {
            float rezultat = op(x, y);
            cout << "Rezultatul: " << rezultat << endl;
        }
    }

    return 0;
}
