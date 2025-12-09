#include "ComputerBook.h"

using namespace std;

ComputerBook::ComputerBook(){
    this->setCode(0);
    this->setTitle("");
    this->publisher = "";
    this->setAvailable(0);
    this->setRented(0);
}

ComputerBook::ComputerBook(int code, string title, string publisher, int available, int rented){
    this->setCode(code);
    this->setTitle(title);
    this->publisher = publisher;
    this->setAvailable(available);
    this->setRented(rented);
}

void ComputerBook::setPublisher(string publisher){
    this->publisher = publisher;
}

string ComputerBook::getPublisher()const{
    return publisher;
}
