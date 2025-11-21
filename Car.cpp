//Un destructor este o metodă specială a unei clase care este apelată automat atunci când obiectul iese din sfera de acțiune sau este șters.

#include <iostream>
using namespace std;
class Car {
public:
    Car() {
        //Initializari
    }

    ~Car() {
        //Eliberari sau stergeri
        cout << "Destructorul clasei Car a fost apelat!" << endl;
    }
};
