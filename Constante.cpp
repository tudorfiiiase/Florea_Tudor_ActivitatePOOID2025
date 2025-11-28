#include <iostream>
#include <string>
using namespace std;

class Constante {
private:
    float valoare;

public:
    const float PI;
    Constante(float val = 0.0f) : PI(3.14f), valoare(val) {}

    void setValoare(float val) {
        valoare = val;
    }

    void getValoare() const {
        cout << "Valoare: " << valoare << endl;
    }
};

int main() {
    Constante c(10.0f);
    c.getValoare();
    cout << "PI: " << c.PI << endl;
    c.setValoare(20.5f);
    c.getValoare();
    return 0;
}
