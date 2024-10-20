#include<iostream>
#include<string>

using namespace std;

class Computer {

private:

	int id;
	string name;
	static int numberOfComputers;
	float price;
	string os;

public:

	Computer() :id(++numberOfComputers) {
		this->name = "undefined";
		this->price = 0.0f;
		this->os = "undefined";
	}

	Computer(string name, float price, string os) :id(++numberOfComputers) {
		this->name = name;
		this->price = price;
		this->os = os;
	}

	void viewComputer() {
		cout << " Id: " << this->id  << 
		endl << " name: " << this->name << 
		endl << " price: "  << this->price << 
		endl <<  " os: " << this->os;
	}
};

int Computer::numberOfComputers = 0;


int main() {
	cout << "Hello World";

	Computer c;
	c = Computer("PC 1", 2500.0f, "Windows");
	c.viewComputer();
}

