#include <iostream>
#include "Book.h"

using namespace std;

class ChildrenBook : public Book{
    private:
        int age;
    public:
        // Constructors
        ChildrenBook();
        ChildrenBook(int age);

        // Setters
        void setAge(int age);
        
        // Getters
        int getAge()const;
        
        // Operator
        

};