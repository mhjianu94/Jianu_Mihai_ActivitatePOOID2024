#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>

using namespace std;

class Computer {

private:
	static int numberOfComputers;
	int id;
	string name;
	float price;
	string os;
	string* components;
	int numberOfComponents;
	char* code;

public:

	Computer() :id(++numberOfComputers) {
		this->name = "undefined";
		this->price = 0.0f;
		this->os = "undefined";
		this->components = nullptr;
		this->numberOfComponents = 0;
		this->code = nullptr;
	}

	Computer(const Computer &computer) :id(++numberOfComputers){
		this->name = computer.name;
		this->price = computer.price;
		this->os = computer.os;
		this->numberOfComponents = computer.numberOfComponents;
		this->components = new string[this->numberOfComponents];

		if (computer.components != nullptr) {
			for (int i = 0; i < this->numberOfComponents; i++) {
				this->components[i] = computer.components[i];
			}
		}
		else {
			this->components = nullptr;
		}

		if (code != nullptr) {
			this->code = new char[strlen(code) + 1];
			strcpy(this->code, computer.code);
		}
		else {
			this->code = nullptr;
		}
	}

	Computer(string name, float price, string os, int numberOfComponents , string* components, const char* code) :id(++numberOfComputers) {
		this->name = name;
		this->price = price;
		this->os = os;
		this->numberOfComponents = numberOfComponents;
		this->components = new string[numberOfComponents];

		for (int i = 0; i < numberOfComponents; i++) {
			this->components[i] = components[i];
		}

		if (code != nullptr) {
			this->code = new char[strlen(code) + 1];
			strcpy(this->code, code);
		}
		else {
			this->code = nullptr;
		}
	}

	Computer(string name, float price, string os, const char* code) :id(++numberOfComputers) {
		this->name = name;
		this->price = price;
		this->os = os;
		this->components = nullptr;
		this->numberOfComponents = 0;

		if (code != nullptr) {
			this->code = new char[strlen(code) + 1];
			strcpy(this->code, code);
		}
		else {
			this->code = nullptr;
		}
	}

	~Computer() {
		if (this->components != nullptr) {
			delete [] components;
		}
		if (this->code != nullptr) {
			delete[] code;
		}
	}

	void viewComputer() {
		cout << endl;
		cout << " Id: " << this->id  << 
		endl << " name: " << this->name << 
		endl << " price: "  << this->price << 
		endl <<  " os: " << this->os <<
		endl << " Components: " << endl;

		for (int i = 0; i < this->numberOfComponents; i++) {
			cout << " Nr: "<< i <<" --> "<< this->components[i] << endl;
		}
		cout << endl;
	}

	void setName(string name) {
	  this->name = name;
	}

	int getId() {
		if (id != 0) {
			return this->id;
		}
	}

	string getName() {
		if (name != "") {
			return this->name;
		}
	}

	void setPrice(float price) {
		if (price > 0) {
			this->price = price;
		}
	}

	float getPrice() {
		return this->price;
	}

	void setOs(string os) {
		if (name != "") {
			this->os = os;
		}
	}

	string getOs() {
		return this->os;
	}

	void setNrComp(int numberOfComponents) {
		this->numberOfComponents = numberOfComponents;
	}

	int getNrComp() {
		return this->numberOfComponents;
	}

	void setComponents(string* components, int numberOfComponents) {

		this->setNrComp(numberOfComponents);

		if (this->components != nullptr) {
			delete[] this->components;
		}
		this->components = new string[this->numberOfComponents];

		for (int i = 0; i < this->numberOfComponents; i++) {
			this->components[i] = components[i];
		}
	}

	string* getComponents() {
		return this->components;	
	}

	string operator[](int index) {
		if (index >= 0) {
			return this->components[index];
		}
	}

	float operator+(float valoare) {
		this->price += valoare;
		return this->price;
	}


};


class Laptop : public Computer {
private:
	string* componenteLaptop;
	int nrComponenteLaptop;
	float greutate;
	int capacitateBaterie;

public:
	Laptop() : Computer() {
		greutate = 0.0f;
		capacitateBaterie = 0;
		componenteLaptop = nullptr;
		nrComponenteLaptop = 0;
	}

	void setNrCompLaptop(int nrComponenteLaptop) {
		this->nrComponenteLaptop = nrComponenteLaptop;
	}

	int getNrCompLaptop() {
		return this->nrComponenteLaptop;
	}

	void setGreutate(float greutate) {
		this->greutate = greutate;
	}

	float getNrGreuatate() {
		return this->greutate;
	}

	void setCapacitateBaterie(int capacitateBaterie) {
		this->capacitateBaterie = capacitateBaterie;
	}

	int getCapacitateBaterie() {
		return this->capacitateBaterie;
	}

	friend Laptop operator+(float valoare, Laptop laptop);

	void setComponenteLaptop(string* componenteLaptop, int nrComponenteLaptop) {
		setNrCompLaptop(nrComponenteLaptop);

		if (this->componenteLaptop != nullptr) {
			delete[] this->componenteLaptop;
		}

		this->componenteLaptop = new string[this->nrComponenteLaptop];

		for (int i = 0; i < this->nrComponenteLaptop; i++) {
			this->componenteLaptop[i] = componenteLaptop[i];
		}
	}

	void viewLaptop() {
		cout << endl;
		cout << " Capacitate Baterie: " << this->capacitateBaterie <<
			endl << " greutate: " << this->greutate <<
			endl << " Components: " << endl;

		for (int i = 0; i < this->nrComponenteLaptop; i++) {
			cout << " Nr: " << i << " --> " << this->componenteLaptop[i] << endl;
		}
		cout << endl;
	}

	string* getComponenteLaptop() {
		return this->componenteLaptop;
	}

	Laptop(string name, float price, string os, int numberOfComponents, string* components, const char* code, int nrComponenteLaptop, string* componenteLaptop, float greutate, int capacitateBaterie) : Computer(name, price, os, numberOfComponents, components, code) {
		this->capacitateBaterie = capacitateBaterie;
		this->nrComponenteLaptop = nrComponenteLaptop;
		this->greutate = greutate;
		this->componenteLaptop = new string[this->nrComponenteLaptop];

		for (int i = 0; i < this->nrComponenteLaptop; i++) {
			this->componenteLaptop[i] = componenteLaptop[i];
		}
	}

	Laptop(const Laptop &laptop) : Computer(laptop) {
		this->capacitateBaterie = laptop.capacitateBaterie;
		this->nrComponenteLaptop = laptop.nrComponenteLaptop;
		this->greutate = laptop.greutate;
		this->componenteLaptop = new string[this->nrComponenteLaptop];

		if (laptop.componenteLaptop != nullptr) {
			for (int i = 0; i < this->nrComponenteLaptop; i++) {
				this->componenteLaptop[i] = laptop.componenteLaptop[i];
			}
		}
		else {
			this->componenteLaptop = nullptr;
		}
	}
	~Laptop() {
		if (this->componenteLaptop != nullptr) {
			delete[] this->componenteLaptop;
		}
	}

	Laptop operator+(float value) {
		Laptop aux = *this;
		aux.greutate += value;
		return aux;
	}

};

Laptop operator+(float valoare, Laptop laptop) {
	Laptop aux = laptop;
	aux.greutate += valoare;
	return aux;
}

int Computer::numberOfComputers = 0;

ostream& operator<<(ostream& oStream, Computer &computer) {
		oStream << endl;
		oStream << " Id: " << computer.getId() <<
		endl << " name: " << computer.getName() <<
		endl << " price: " << computer.getPrice() <<
		endl << " os: " << computer.getOs() <<
		endl << " Components: " << endl;

	for (int i = 0; i < computer.getNrComp(); i++) {
		cout << " Nr: " << i << " --> " << computer.getComponents()[i] << endl;
	}
	cout << endl;

	return oStream;
}

istream &operator>> (istream &Istream, Computer &computer) {
		cout << endl;
		cout << " Id: " << computer.getId();

		string name;
		cout << endl << " name: ";
		Istream >> name;
		computer.setName(name);

		float price;
		cout << endl << " price: ";
		Istream >> price;
		computer.setPrice(price);

		string os;
		cout << endl << " os: ";
		Istream >> os;
		computer.setOs(os);

		int nrComponente;
		cout << endl << " nrComponente: ";
		Istream >> nrComponente;
		computer.setNrComp(nrComponente);

		string* tempComputerComp = new string[nrComponente];

	for (int i = 0; i < computer.getNrComp(); i++) {
		cout << endl << " Nr: " << i << " --> ";
		Istream >> tempComputerComp[i];
	}

	computer.setComponents(tempComputerComp, nrComponente);
	cout << endl;

	return Istream;
}

int main() {

	Computer c1("PC 1", 2500.0f, "Windows",6,new string[6] {"GPU","Motherboard","RAM","Hardrive","Case","Other"},"PC2024");
	c1.viewComputer();

	 
	Computer c2("PC 2", 3500.0f, "Windows","PC2024");
	c2.setComponents(new string[6]{ "GPU1","Motherboard1","RAM1","Hardrive1","Case1","Other1" },6);
	c2.viewComputer();

	string* components = c2.getComponents();

	for (int i = 0; i < c2.getNrComp(); i++) {
		cout << endl << " Nr: " << i << " --> " << components[i];
	}

	Computer c3 = c2;
	cout << c3;

	Laptop l1("PC 1", 2500.0f, "Windows", 6, new string[6]{ "GPU","Motherboard","RAM","Hardrive","Case","Other" }, "PC2024",3, new string[3]{"Camera","Touchpad","microfon"},1000.5f,5000);
	l1.viewComputer();
	l1.viewLaptop();
	
	Laptop l2 = l1 + 2000.0f;
	l2.viewLaptop();

	Computer c4;
	//cin >> c4;
	//c4.viewComputer();

	cout << "Components:" << endl;
	for (int i = 0; i < c3.getNrComp(); i++) {
		cout<< "Componenta " << i <<": " << c3[i]<<endl;
	}
	
}

