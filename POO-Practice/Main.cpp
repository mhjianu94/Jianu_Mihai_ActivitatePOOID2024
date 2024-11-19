#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

class Tren {
private:
	static int nrTrenuri;
	int idTren;
	int capacitate;
	int nrPasageri;
	char* operatorTren;
public:
	Tren():idTren(++nrTrenuri) {
		this->capacitate = 1000;
		this->nrPasageri = 0;
		this->operatorTren = new char[8];
		strcpy(this->operatorTren, "Default");
	}

	Tren(int capacitate,int nrPasageri,const char* operatorTren) :idTren(++nrTrenuri) {
		this->capacitate = capacitate;
		this->nrPasageri = nrPasageri;
		this->operatorTren = new char[strlen(operatorTren)+1];
		strcpy(this->operatorTren, operatorTren);
	}

	~Tren() {
		if (this->operatorTren != nullptr) {
			delete[] operatorTren;
		}
	}

	int getId() {
		return this->idTren;
	}
	int getCapacitate() {
		return this->capacitate;
	}
	int getNrPasageri() {
		return this->nrPasageri;
	}
	char* getOperator() {
		return this->operatorTren;
	}


};

ostream& operator<<(ostream& stream, Tren &tren) {
	cout << endl << 
		tren.getId() << ";" 
		<< tren.getCapacitate() << ";"
		<< tren.getNrPasageri() << ";"
		<<  tren.getOperator() << ";";

	return stream;
}

int Tren::nrTrenuri = 0;

int main() {
	Tren t1 = Tren();
	cout << t1<<endl;

	Tren t2 = Tren(3500,1000,"CFR");
	cout << t2 << endl;;
	return 0;
}