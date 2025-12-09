#ifndef NOVEL_H
#define NOVEL_H

#include <iostream>
#include "Book.h"

using namespace std;

class Novel : public Book {
    private:
        int publishYear; 
    public: 
        // Constructors
        Novel();
        Novel(int code, string title, int publishYear, int available, int rented);

        // Setters
        void setPublishYear(int publishYear);
            
        // Getters
        int getPublishYear()const;

        // Operators

};
#endif