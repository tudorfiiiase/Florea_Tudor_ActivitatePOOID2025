#include <iostream>

// Funcția suma cu doi parametri
int suma(int a, int b) {
    return a + b;
}

// Funcția suma cu trei parametri
int suma(int a, int b, int c) {
    return a + b + c;
}

int main() {
    // Apelăm funcția suma cu doi parametri
    int rezultat1 = suma(3, 9);
    std::cout << "Suma a doua numere: " << rezultat1 << std::endl;

    // Apelăm funcția suma cu trei parametri
    int rezultat2 = suma(3, 5, 9);
    std::cout << "Suma a trei numere: " << rezultat2 << std::endl;

    return 0;
}
