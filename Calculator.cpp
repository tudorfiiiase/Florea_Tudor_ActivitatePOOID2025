#include <iostream>
#include <string>
using namespace std;

class Calculator {
public:
    inline float adunare(float a, float b) {
        return a + b;
    }

    inline float scadere(float a, float b) {
        return a - b;
    }

    inline float inmultire(float a, float b) {
        return a * b;
    }

    inline float impartire(float a, float b) {
        if (b != 0) {
            return a / b;
        }
        else {
            std::cerr << "Eroare: Împărțire la zero!\n";
            return 0.0f;
        }
    }
};

int main() {
    Calculator calc;

    float x = 10.0f, y = 5.0f;

    std::cout << "Adunare: " << calc.adunare(x, y) << std::endl;
    std::cout << "Scadere: " << calc.scadere(x, y) << std::endl;
    std::cout << "Inmultire: " << calc.inmultire(x, y) << std::endl;
    std::cout << "Impartire: " << calc.impartire(x, y) << std::endl;

    return 0;
}
