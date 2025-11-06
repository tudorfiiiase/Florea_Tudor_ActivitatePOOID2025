#include <iostream>
#include <string>
using namespace std;

class Persoana {
private:
	string nume;
	int varsta;

protected:
	string CNP;

public:
	char gen;
	Persoana() : nume(""), varsta(0), CNP(""), gen('X') {}
	Persoana(const string& nume, int varsta, const string& CNP, char gen) : nume(nume), varsta(varsta), CNP(CNP), gen(gen) {

	}
	void setNume(const string& nume) {
		this->nume = nume;
	}
	string getNume() const {
		return this->nume;
	}
	void setVarsta(int varsta) {
		this-> varsta = varsta;
	}
	int getVarsta() const {
		return this->varsta;
	}

	void afiseazaInformatii() const {
		cout << "Nume: " << nume << endl;
		cout << "Varsta: " << varsta << endl;
		cout << "Gen: " << gen << endl;
		cout << "CNP: " << CNP << endl;
	}
};

int main() {
	Persoana p("Florea Tudor", 22, "5020830460038", 'M');
	p.afiseazaInformatii();
	cout << "..............." << endl;
	p.setNume("Gheorghe Lavinia");
	p.setVarsta(28);
	cout << "Nume actualizat: " << p.getNume() << endl;
	cout << "Varsta actualizata: " << p.getVarsta() << endl;
	cout << "..............." << endl;
	p.afiseazaInformatii();
	return 0;
}

