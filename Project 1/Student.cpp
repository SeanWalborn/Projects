#include "Student.h"
#include <iomanip>

using namespace std;

// constructors
Student::Student() : id(0), name("empty"), score(0) {}
Student::Student(int i, string n, int s) : id(i), name(n), score(s){}
Student::Student(const Student& s) : id(s.id), name(s.name), score(s.score) {}
Student::~Student(){}

// Setters
void Student::setID(int i){
    id = i;
}

void Student::setName(string n){
    name = n;
} 
void Student:: setScore(int s){
    score = s;
}

// getters
int Student::getID()const{
    return id;
}
string Student::getName()const{
    return name;
}
int Student::getScore()const{
    return score;
}

//operators
Student& Student::operator=(const Student& rightSide){
    id = rightSide.id;
    name = rightSide.name;
    score = rightSide.score;
}

ostream& operator<<(ostream& os, const Student& s){
    os <<setw(10) << s.id << setw(10) << s.name << setw(4) << s.score << endl; 
    return os;
}

istream& operator>>(istream& is, Student& s){
    is >> s.id >> s.name >> s.score;
    return is;
}