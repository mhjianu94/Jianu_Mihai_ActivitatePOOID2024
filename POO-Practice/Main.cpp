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

	Autobuz():idAutobuz(++nrAutobuze) {
		this->capacitate = 10;
		this->nrPersoaneImbarcate = 0;
		this->producator = new char[20];
	};

	Autobuz( int capacitate,int nrPersoaneImbarcate,const char* producator) :idAutobuz(++nrAutobuze) {
		this->capacitate = capacitate;
		this->nrPersoaneImbarcate = nrPersoaneImbarcate;
		this->producator = new char[strlen(producator)+1];
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
		this->producator = new char[strlen(producator)+1];
		strcpy(this->producator, producator);
	}

};

int Autobuz::nrAutobuze = 0;

int main() {

	Autobuz autobuz1 = Autobuz();
	cout << autobuz1.getNrPersoaneImbarcate();

	Autobuz autobuz2 = Autobuz(20,10,"MARLIN");
	cout << autobuz2.getNrPersoaneImbarcate();
	cout << autobuz2.getProducator();

	return 0;
}
