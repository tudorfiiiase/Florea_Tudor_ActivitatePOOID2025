#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    const float PI = 3.14159f; // Definim o constantă PI
    float raza = 5.0f;         // Raza cercului
    float aria = PI * raza * raza;

    cout << "Aria unui cerc cu raza de " << raza << " este: " << aria << endl;

    return 0;
}
