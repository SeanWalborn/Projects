#include "Novel.h"

using namespace std;

Novel::Novel(){
    this->setCode(0);
    this->setTitle("");
    this->publishYear = 0;
    this->setAvailable(0);
    this->setRented(0);
}

Novel::Novel(int code, string title, int publishYear, int available, int rented){
    this->setCode(code);
    this->setTitle(title);
    this->publishYear = publishYear;
    this->setAvailable(available);
    this->setRented(rented);
}

void Novel::setPublishYear(int publishYear){
    this->publishYear = publishYear;
}

int Novel::getPublishYear()const{
    return publishYear;
}