#ifndef CHILDRENBOOK_H
#define CHILDRENBOOK_H

#include <iostream>
#include "Book.h"

using namespace std;

class ChildrenBook : public Book{
    private:
        int age;
    public:
        // Constructors
        ChildrenBook();
        ChildrenBook(int code, string title, int age, int available, int rented);

        // Setters
        void setAge(int age);
            
        // Getters
        int getAge()const;
        
        // Operator
        

};
#endif