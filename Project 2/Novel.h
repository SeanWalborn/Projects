#include <iostream>
#include "Book.h"

using namespace std;

class Novel : public Book {
    private:
        int publishYear; 
    public: 
        // Constructors
        Novel();
        Novel(int publishYear);

        // Setters
        void setPublishYear(int publishYear);

        // Getters
        int getPublishYear()const;

        // Operators

};