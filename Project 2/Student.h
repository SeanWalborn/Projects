#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "Person.h"

using namespace std;

class Student:public Person{
    private:
        int* code; 

    public:
        // Constructors
        Student();
        Student(int id, string name, int count, int* code);
        ~Student();

        // Setters
        void setCode(int* code);

        // Getters
        int* getCode()const;
};
#endif