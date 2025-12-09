#include "ChildrenBook.h"

using namespace std;

ChildrenBook::ChildrenBook(){
    this->setCode(0);
    this->setTitle("");
    this->age = 0;
    this->setAvailable(0);
    this->setRented(0);
}

ChildrenBook::ChildrenBook(int code, string title, int age, int available, int rented){
    this->setCode(code);
    this->setTitle(title);
    this->age = age;
    this->setAvailable(available);
    this->setRented(rented);
}

void ChildrenBook::setAge(int age){
    this->age = age;
}

int ChildrenBook::getAge()const{
    return age;
}

