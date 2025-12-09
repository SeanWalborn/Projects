#include "HistoryBook.h"

using namespace std;

HistoryBook::HistoryBook(){
    this->setCode(0);
    this->setTitle("");
    this->author = "";
    this->setAvailable(0);
    this->setRented(0);
}

HistoryBook::HistoryBook(int code, string title, string author, int available, int rented){
    this->setCode(code);
    this->setTitle(title);
    this->author = author;
    this->setAvailable(available);
    this->setRented(rented);
}

void HistoryBook::setAuthor(string author){
    this->author = author;
}

string HistoryBook::getAuthor()const{
    return author;
}