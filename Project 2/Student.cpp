#include "Student.h"

using namespace std;

 // Constructors
Student::Student(){
    this->setId(0);
    this->setName("");
    this->setCount(0);
    this->code = nullptr;
}
Student::Student(int id, string name, int count, int* code){
    this->setId(id);
    this->setName(name);
    this->setCount(count);
    this->code = code;
}
Student::~Student(){
    delete[] code;
}

// Setters
void Student::setCode(int* code){
    this->code = code;
}
        
// Getters
int* Student::getCode()const{
    return code;
}