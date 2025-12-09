#ifndef STAFF_H
#define STAFF_H

#include <iostream>
#include "Person.h"

using namespace std;

class Staff: public Person{
    private:
        int* code;
    public:
        // Constructors
        Staff();
        Staff(int id, string name, int count, int* code);
        ~Staff();

        // Setters
        void setCode(int* Code);

        // Getters
        int* getCode()const;    
};
#endif