#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

class Masina {
private:
	char* nrInmatriculare;
	static int nrMasini;
	const int numarOrdineMasina;
	int locuri;
	const int roti;
	float combustibil;
	const int capacitateRezervor;

public:

	Masina() :numarOrdineMasina(++nrMasini), roti(4), capacitateRezervor(40){
		this->combustibil = 10.2;
		this->locuri = 5;
		this->nrInmatriculare = new char[8];
		strcpy(this->nrInmatriculare, "0000000");
	}

	Masina(float combustibil, int locuri , const char* nrInmatriculare) :numarOrdineMasina(++nrMasini), roti(4), capacitateRezervor(40) {
		this->combustibil = 10.2;
		this->locuri = 5;
		this->nrInmatriculare = new char[strlen(nrInmatriculare)+1];
		strcpy(this->nrInmatriculare, nrInmatriculare);
	}

	~Masina() {
		if (this->nrInmatriculare != nullptr) {
			delete[] this->nrInmatriculare;
		}
	}

	void setCombustibil(float combustibil) {
		this->combustibil = combustibil;
	}

	float getCombustibil() {
		return this->combustibil;
	}

	void afisareMasina() {
		cout  << endl;
		cout << "numarOrdineMasina: " << this->numarOrdineMasina << endl;
		cout << "nrInmatriculare: " << this->nrInmatriculare << endl;
		cout << "capacitateRezervor: " << this->capacitateRezervor << endl;
		cout << "combustibil: " << this->combustibil << endl;
		cout << "roti: " << this->roti << endl;
		cout << "locuri: " << this->locuri << endl;
	}

	friend istream& operator>>(istream& stream, Masina& masina) {
		float valoare;
		cin >> valoare;
		masina.setCombustibil(valoare + masina.getCombustibil());
		return stream;
	};


	Masina operator+ (float value) {
		Masina masina = *this;
		masina.combustibil += value;
		return masina;
	}

};

int Masina::nrMasini = 0;

int main() {

	Masina masina1 = Masina();
	masina1.afisareMasina();

	Masina masina2 = Masina(15.3f, 6,"CT27JMH");
	masina2.afisareMasina();
	masina2 = masina2 + 1.3f;
	cin >> masina2;

	masina2.afisareMasina();


	return 1;
}