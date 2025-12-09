#include "Adult.h"

using namespace std;

 // Constructors
Adult::Adult(){
    this->setId(0);
    this->setName("");
    this->setCount(0);
    this->code = nullptr;
}
Adult::Adult(int id, string name, int count, int* code){
    this->setId(id);
    this->setName(name);
    this->setCount(count);
    this->code = code;
}
Adult::~Adult(){
    delete[] code;
}

// Setters
void Adult::setCode(int* code){
    this->code = code;
}
        
// Getters
int* Adult::getCode()const{
    return code;
}