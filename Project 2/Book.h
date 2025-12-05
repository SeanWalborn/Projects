#include <iostream>

using namespace std;

class Book {
    private:
        int code;
        string title;
        int available;
        int rented;
    public:
        // Constructors
        Book();
        Book(int code, string title, int available, int rented);

        // Setters
        void setCode(int code);
        void setTitle(string title);
        void setAvailable(int available);
        void setRented(int rented);

        // Getters
        int getCode()const;
        string getTitle()const;
        int getAvailable()const;
        int getRented()const;

        // Operators
};