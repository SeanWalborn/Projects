#include "Staff.h"

using namespace std;

 // Constructors
Staff::Staff(){
    this->setId(0);
    this->setName("");
    this->setCount(0);
    this->code = nullptr;
}
Staff::Staff(int id, string name, int count, int* code){
    this->setId(id);
    this->setName(name);
    this->setCount(count);
    this->code = code;
}
Staff::~Staff(){
    delete[] code;    
}

// Setters
void Staff::setCode(int* code){
    this->code = code;
}
        
// Getters
int* Staff::getCode()const{
    return code;
}