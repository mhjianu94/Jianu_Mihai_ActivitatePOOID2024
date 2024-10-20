
#ifndef COMPUTER_H
#define COMPUTER_H

class Computer {
    int id;
    std::string name;
    static int numberOfComputers; 
    float price;
    std::string os;

public:
    Computer();
    Computer(std::string name, float price, std::string os);

    void display();         
    static int getNumberOfComputers() { return numberOfComputers; }  
    ;
};

#endif 