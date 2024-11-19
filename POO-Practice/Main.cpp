#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

class Autobuz {

private:
	static int nrAutobuze;
	const int idAutobuz;
	int capacitate;
	int nrPersoaneImbarcate;
	char* producator;
public:

	Autobuz() :idAutobuz(++nrAutobuze) {
		this->capacitate = 10;
		this->nrPersoaneImbarcate = 0;
		this->producator = new char[20];
	};

	Autobuz(int capacitate, int nrPersoaneImbarcate, const char* producator) :idAutobuz(++nrAutobuze) {
		this->capacitate = capacitate;
		this->nrPersoaneImbarcate = nrPersoaneImbarcate;
		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);

	};

	~Autobuz() {
		if (producator != nullptr) {
			delete[] producator;
		}
	}

	int getNrPersoaneImbarcate() {
		return this->nrPersoaneImbarcate;
	}

	void setNrPersoaneImbarcate(int nrPersoaneImbarcate) {
		this->nrPersoaneImbarcate = nrPersoaneImbarcate;
	}

	char* getProducator() {
		return this->producator;
	}

	void setProducator(char* producator) {
		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);
	}

	int getNrLocuriLibere() {
		return capacitate - nrPersoaneImbarcate;
	}

	Autobuz& operator=(Autobuz& autobuz) {
		if (this != &autobuz) {
			delete[] this->producator;
			this->capacitate = autobuz.capacitate;
			this->nrPersoaneImbarcate = autobuz.nrPersoaneImbarcate;

			this->producator = new char[strlen(autobuz.producator) + 1];
			strcpy(this->producator, autobuz.producator);

		}
		return *this;
	}

	bool operator>(Autobuz &a1) {
		return this->capacitate  > a1.capacitate;
	}

	operator int() {
		return this->nrPersoaneImbarcate;
	}

};

ostream& operator<<(ostream& stream, Autobuz& autobuz) {
	cout << autobuz.getNrPersoaneImbarcate() << ";" << autobuz.getProducator() << ";";
	return stream;
};

int Autobuz::nrAutobuze = 0;

int main() {

	Autobuz autobuz1 = Autobuz();
	Autobuz autobuz2 = Autobuz(20, 10, "MARLIN");

	cout << "Get Persoane imbarcate:" << autobuz2.getNrPersoaneImbarcate() << endl;
	cout << "Get producator:" << autobuz2.getProducator() << endl;
	cout << "Operator <<:" << autobuz2 << endl;
	cout << "Metoda locuri ramase libere: " << autobuz2.getNrLocuriLibere() << endl;
	cout << "Comparatie: " << (autobuz1 > autobuz2) << endl;
	cout << "Persoane imbarcate: " << (int)autobuz2 << endl;

	autobuz1 = autobuz2;
	cout << "Dupa atribuire: " << autobuz1 << endl;


	return 0;
}
