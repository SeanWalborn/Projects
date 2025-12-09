#ifndef ADULT_H
#define ADULT_H 

#include <iostream>
#include "Person.h"

using namespace std;

class Adult:public Person{
    private:
        int* code;
    public:
        // Constructors /destructors
        Adult();
        Adult(int id, string name, int count, int* code);
        ~Adult();

        // Setters
        void setCode(int* code);
                
        // Getters
        int* getCode()const;

};
#endif