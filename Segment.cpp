#include <iostream>
#include <cmath> // For sqrt
using namespace std;

class Punct {
private:
    float x, y;
public:
    Punct(float x = 0, float y = 0) {
        this->x = x;
        this->y = y;
        cout << "Apel constructor cu parametri pentru clasa Punct (" << x << "," << y << ")" << endl;
    }

    ~Punct() {
        cout << "Apel destructor clasa Punct. Se distruge obiectul Punct (" << x << "," << y << ")" << endl;
    }

    void afisare() {
        cout << "(" << x << "," << y << ")";
    }

    float getX() const { return x; }
    float getY() const { return y; }
};

class Segment {
private:
    Punct O; // Endpoint 1
    Punct V; // Endpoint 2
public:
    Segment(float x1, float y1, float x2, float y2) : O(x1, y1), V(x2, y2) {
        cout << "Apel constructor clasa Segment" << endl;
    }

    ~Segment() {
        cout << "Apel destructor clasa Segment" << endl;
    }

    void afisare() {
        cout << "[";
        O.afisare();
        cout << " , ";
        V.afisare();
        cout << "]" << endl;
    }

    float lungime() {
        float dx = V.getX() - O.getX();
        float dy = V.getY() - O.getY();
        return sqrt(dx * dx + dy * dy);
    }
};

int main() {
    Segment s(0, 0, 3, 4);
    s.afisare();
    cout << "Lungimea segmentului: " << s.lungime() << endl;
    return 0;
}
