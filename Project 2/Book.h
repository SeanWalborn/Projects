#ifndef BOOK_H
#define BOOK_H

#include <iostream>

using namespace std;

class Book {
    private:
        int code;
        string title;
        int available;
        int rented;
    public:
        // Constructors / destruct
        Book();
        Book(int code, string title, int available, int rented);
        virtual ~Book();

        // Setters
        void setCode(int code);
        void setTitle(string title);
        void setAvailable(int available);
        void setRented(int rented);
        virtual void setAge();
        virtual void setPublisher();
        virtual void setPublishYear();
        virtual void setAuthor();

        // Getters
        int getCode()const;
        string getTitle()const;
        int getAvailable()const;
        int getRented()const;
        virtual int getAge()const;
        virtual string getPublisher() const;
        virtual int getPublishYear() const;
        virtual string getAuthor() const;

        // Operators
};
#endif