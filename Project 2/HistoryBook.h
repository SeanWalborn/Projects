#include <iostream>
#include "Book.h"

using namespace std;

class HistoryBook : public Book {
    private:
        string author;
    public: 
        // Constructors
        HistoryBook();
        HistoryBook(string author);

        // Setters
        void setAuthor(string author);

        // Getters
        string getAuthor()const;

        // Operators
};