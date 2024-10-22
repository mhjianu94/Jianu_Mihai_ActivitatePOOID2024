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
	}

	Computer(string name, float price, string os, int numberOfComponents , string* components) :id(++numberOfComputers) {
		this->name = name;
		this->price = price;
		this->os = os;
		this->numberOfComponents = numberOfComponents;
		this->components = new string[numberOfComponents];
		for (int i = 0; i < numberOfComponents; i++) {
			this->components[i] = components[i];
		}
	}

	Computer(string name, float price, string os) :id(++numberOfComputers) {
		this->name = name;
		this->price = price;
		this->os = os;
		this->components = nullptr;
		this->numberOfComponents = 0;
	}

	~Computer() {
		if (this->components != nullptr) {
			delete [] components;
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

	string setName(string name) {
	  this->name = name;
	}

	string getName() {
		if (name != "") {
			return this->name;
		}
	}

	int setPrice(float price) {
		if (price > 0) {
			this->price = price;
		}
	}

	float getPrice() {
		return this->price;
	}

	string setOs(string os) {
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

};

int Computer::numberOfComputers = 0;


int main() {

	Computer c1("PC 1", 2500.0f, "Windows",6,new string[6] {"GPU","Motherboard","RAM","Hardrive","Case","Other"});
	c1.viewComputer();

	 
	Computer c2("PC 2", 3500.0f, "Windows");
	c2.setComponents(new string[6]{ "GPU1","Motherboard1","RAM1","Hardrive1","Case1","Other1" },6);
	c2.viewComputer();

	string* components = c2.getComponents();

	for (int i = 0; i < c2.getNrComp(); i++) {
		cout << endl << " Nr: " << i << " --> " << components[i];
	}

	Computer c3 = c2;
	c3.viewComputer();

}

