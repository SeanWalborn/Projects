#include <iostream>
#include "Person.h"

using namespace std;

class Staff: public Person{
    private:
        int code[3];
    public:
        // Constructors
        Staff();
        Staff(int Code);

        // Setters
        void setCode(int Code);

        // Getters
        int getCode()const;    
};