#include "Person.h"

using namespace std;
     
Person::Person(){
    this->id = 0;
    this->name = "";
    this->count = 0;
}
Person::Person(int id, string name, int count){
    this->id = id;
    this->name = name;
    this->count = count;
}
Person::~Person(){}

void Person::setId(int id){
    this->id = id;
}
void Person::setName(string name){
    this->name = name;
}
void Person::setCount(int count){
    this->count = count;
}

int Person::getId()const{
    return id;
}
string Person::getName()const{
    return name;    
}
int Person::getCount()const{
    return count;
}

