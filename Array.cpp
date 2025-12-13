#include <iostream>
using namespace std;

// Structură pentru gestionarea unui array dinamic
struct ArrayDinamic {
    int* array;       // Pointer către array
    int capacitate;   // Capacitatea maximă a array-ului
    int dimensiune;   // Numărul curent de elemente

    // Constructor
    ArrayDinamic(int capacitateInitiala) {
        capacitate = capacitateInitiala;
        dimensiune = 0;
        array = new int[capacitate];
    }

    // Destructor
    ~ArrayDinamic() {
        delete[] array;
    }
};

// Funcție pentru redimensionarea array-ului
void redimensioneaza(ArrayDinamic& arr, int nouaCapacitate) {
    int* nouArray = new int[nouaCapacitate];
    for (int i = 0; i < arr.dimensiune; i++) {
        nouArray[i] = arr.array[i];
    }
    delete[] arr.array;
    arr.array = nouArray;
    arr.capacitate = nouaCapacitate;
}

// Funcție pentru adăugarea unui element
void adaugaElement(ArrayDinamic& arr, int element) {
    if (arr.dimensiune == arr.capacitate) {
        redimensioneaza(arr, arr.capacitate * 2); // Dublăm capacitatea
    }
    arr.array[arr.dimensiune++] = element;
}

// Funcție pentru eliminarea unui element de la o anumită poziție
void eliminaElement(ArrayDinamic& arr, int index) {
    if (index < 0 || index >= arr.dimensiune) {
        cout << "Index invalid!" << endl;
        return;
    }
    for (int i = index; i < arr.dimensiune - 1; i++) {
        arr.array[i] = arr.array[i + 1];
    }
    arr.dimensiune--;

    // Reducem dimensiunea array-ului dacă utilizăm prea puțină memorie
    if (arr.dimensiune < arr.capacitate / 4 && arr.capacitate > 2) {
        redimensioneaza(arr, arr.capacitate / 2);
    }
}

// Funcție pentru afișarea elementelor din array
void afiseazaArray(const ArrayDinamic& arr) {
    for (int i = 0; i < arr.dimensiune; i++) {
        cout << arr.array[i] << " ";
    }
    cout << endl;
}

int main() {
    // Creăm un array dinamic cu o capacitate inițială de 2
    ArrayDinamic arr(2);

    // Adăugăm elemente
    adaugaElement(arr, 10);
    adaugaElement(arr, 20);
    adaugaElement(arr, 30);
    adaugaElement(arr, 40);

    cout << "Array dupa adaugare: ";
    afiseazaArray(arr);

    // Eliminăm un element
    eliminaElement(arr, 1); // Eliminăm elementul de pe poziția 1
    cout << "Array dupa eliminarea elementului de la index 1: ";
    afiseazaArray(arr);

    // Adăugăm mai multe elemente
    adaugaElement(arr, 50);
    adaugaElement(arr, 60);

    cout << "Array dupa adaugarea altor elemente: ";
    afiseazaArray(arr);

    return 0;
}
