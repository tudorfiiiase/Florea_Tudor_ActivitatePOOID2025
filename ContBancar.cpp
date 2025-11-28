#include<iostream>
#include<string>
using namespace std;

class ContBancar {
private:
	float suma;

protected:
	void afisareSuma() const {
		cout << "Suma:" << suma << " " << "de lei."<< endl;
	}

public:
	ContBancar(float sumainitiala = 0.0) : suma(sumainitiala) {}
	void depundere(float v) {
		if (v < 0)
			cout << "Valoarea trebuie sa fie pozitiva!" << endl;
		else
		{
			suma += v;
			cout << "S-au depus " << v << " de lei." << endl;
		}
	};
	void retragere(float v) {
		if (v > 0 && v <= suma)
		{
			suma -= v;
			cout << "S-au retras " << v << " de lei." << endl;
		}
		else if (v > suma)
			cout << "Cont 0!" << endl;
		else
			cout << "Valoarea trebuie sa fie pozitiva!" << endl;
	}
};

int main()
{
	ContBancar cont(1000.0);
	cont.depundere(300.0);
	cont.retragere(200.0);
	return 0;
}