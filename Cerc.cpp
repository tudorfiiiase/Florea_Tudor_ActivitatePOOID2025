#include <iostream>
#include <string>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
using namespace std;

class Cerc {
private:
	float raza;

public:
    Cerc(float r) : raza(r) {

    }
		float Aria() {
			return M_PI * raza * raza;
		}
        float Circumferinta() {
            return 2.0f * M_PI * raza;
    }
        void afiseazainformatiicerc() {
            cout << "Cerc cu raza: " << raza << endl;
            cout << "Aria: " << Aria() << endl;
            cout << "Circumferinta: " << Circumferinta() << endl;
    }
};

int main() {
    
    Cerc c(5.0f);
    c.afiseazainformatiicerc();
    return 0;
}
