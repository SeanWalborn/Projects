#include <iostream>

using namespace std;

class Person{
    private:
        int id;
        string name;
        int count;
    public:
        // Constructors
        Person();
        Person(int id, string name, int count);
        
        // Setters
        void setId(int id);
        void setName(string name);
        void setCount(int count);

        // Getters
        int getId()const;
        string getName()const;
        int getCount()const;
};