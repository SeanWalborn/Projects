
#include <iomanip> 

using namespace std;

class Student{
    public:
        // constructors & destructors
        Student(); // default
        Student(int i, string n, int s);
        Student(const Student& s); // copy
        ~Student();

        // setters
        void setID(int i);
        void setName(string n);
        void setScore(int s);

        // getters
        int getID() const;
        string getName() const;
        int getScore() const;

        // operators
        Student& operator= (const Student& rightSide);
        friend ostream& operator<<(ostream& os, const Student& s);
        friend istream& operator>>(istream& is, Student& s);

    private:
        int id;
        string name;
        int score;
};