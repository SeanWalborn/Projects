#include <iostream>
#include "Book.h"

using namespace std;

Book::Book(){
    this->code = 0;
    this->title = "";
    this->available = 0;
    this->rented = 0;
}

Book::Book(int code, string title, int available, int rented){
    this->code = code;
    this->title = title;
    this->available = available;
    this->rented = rented;
}
Book::~Book(){}

void Book::setCode(int code){
    this->code = code;
}

void Book::setTitle(string title){
    this->title = title;
}

void Book::setAvailable(int available){
    this->available = available;
}

void Book::setRented(int rented){
    this->rented = rented;
}

void Book::setAge(){}
void Book::setPublisher(){}
void Book::setPublishYear(){}
void Book::setAuthor(){}

int Book::getCode()const {
    return code;
}

string Book::getTitle()const {
    return title;
}

int Book::getAvailable()const {
    return available;
}

int Book::getRented()const {
    return rented;
}

int Book::getAge()const{ return 0;}
string Book::getPublisher() const{ return "";}     
int Book::getPublishYear() const{ return 0;}
string Book::getAuthor() const{ return "";}
