#ifndef PERSON_H
#define PERSON_H

#include <iostream>

using namespace std;

class Person{
    private:
        int id;
        string name;
        int count;
    public:
        // Constructors / destructor
        Person();
        Person(int id, string name, int count);
        virtual ~Person();
        
        // Setters
        void setId(int id);
        void setName(string name);
        void setCount(int count);
        virtual void setCode(int* code) = 0;

        // Getters
        int getId()const;
        string getName()const;
        int getCount()const;
        virtual int* getCode() const = 0;
};
#endif