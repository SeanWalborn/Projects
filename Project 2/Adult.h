#include <iostream>
#include "Person.h"

using namespace std;

class Adult:public Person{
    private:
        int code[4];
    public:
        // Constructors
        Adult();
        Adult(int code);

        // Setters
        void setCode(int code);
                
        // Getters
        int getCode()const;

};