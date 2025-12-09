#ifndef COMPUTERBOOK_H
#define COMPUTERBOOK_H

#include <iostream>
#include "Book.h"

using namespace std;

class ComputerBook : public Book{
    private:
        string publisher;
    public:
        // Contsructors
        ComputerBook();
        ComputerBook(int code, string title, string publisher, int available, int rented);

        // Setters
        void setPublisher(string publisher);

        // Getters
        string getPublisher()const;
};
#endif