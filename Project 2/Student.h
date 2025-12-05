#include <iostream>
#include "Person.h"

using namespace std;

class Student:public Person{
    private:
        int code[4]; 

    public:
        // Constructors
        Student();
        Student(int code);

        // Setters
        void setCode(int Code);

        // Getters
        int getCode()const;
};