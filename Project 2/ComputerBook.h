#include <iostream>
#include "Book.h"

using namespace std;

class ComputerBook : public Book{
    private:
        string publisher;
    public:
        // Contsructors
        ComputerBook();
        ComputerBook(string publisher);

        // Setters
        void setPublisher(string publisher);

        // Getters
        string getPublisher()const;

        // Operators
};