#ifndef HISTORYBOOK_H
#define HISTORYBOOK_H

#include <iostream>
#include "Book.h"

using namespace std;

class HistoryBook : public Book {
    private:
        string author;
    public: 
        // Constructors
        HistoryBook();
        HistoryBook(int code, string title, string author, int available, int rented);

        // Setters
        void setAuthor(string author);

        // Getters
        string getAuthor()const;

        // Operators
};
#endif