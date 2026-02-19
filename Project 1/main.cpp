/*
    This project collects three files from the user. each file contains the class name, the number of students in the class, and the students information (ID, name, class grade)
    the program then presents the user with 5 options that repeat until the user picks option 5 at which point the program ends. the other four options manipulate the data in different ways based on the users selection.
*/ 

#include <iomanip>
#include <fstream>
#include <iostream>
#include "Student.cpp"  // compiler doesnt work with "Student.h"

using namespace std;

// global variable used for static arrays
const int N = 3;

// struct declaration
struct course {
    string title;
    int number_of_students;
    Student* list;
};

struct student3Course{
    int ID;
    string name;
    int score1;
    int score2;
    int score3;
};

struct student2Course{
    int ID;
    string name;
    int score1;
    int score2;
};

struct studentHighScore{
    int ID;
    string name;
};

// helper function declaration
void openFile(string fileName, course& c, Student*& s ); // passing student pointer as a ref so it updates in the main
int menuChoice(); // displays menu and returns users choice
void option1(course c[]); // prints sorted list of all classes
void option2(course c[]); // prints list of students taking all three course
    student3Course* resize3Course(student3Course* s, int); // resizes array of students that take three courses
    void sort3Course(student3Course*& s, int); // sorts araray of students who take three courses
    void print3Course(student3Course* s, course c[], int); // prints out array of students who take 3 courses
void option3(course c[]); // prints list of students taking only two course
    void check2Course(course c[], int, int, int); // checks for match in 2 classes but not the third
    student2Course* resize2Course(student2Course* s, int); // resizes array of students that take two course
    void sort2Course(student2Course*& s, int); // sorts arr of students who take 2 courses
    void print2Course(student2Course*s, string c1, string c2, int); // print our arr of students who take 2 courses 
void option4(course c[]); // prints out top three scores for each course
    void findHighScore(course);// finds the three high scores when passed a single course struct
    void findStud(course, int ); // finds students with a given score and sorts in ascending order and prints array
    studentHighScore* resizeHighScore(studentHighScore* s, int); //dynamically resizes array of students with a high score
void option5(bool &b, Student* []); // delete all dynamic memory ends program


int main(){
    // Variables
    string classNameArr[N]; // hold names of classes
    course classArr[N]; // hold class struct
    Student* studentArr[N]; //holds dynamic array of all students
    bool run = true;
    
    // collecting input / oppening file / filling struct arr / building dynamic arr and filling
    for (int i = 0; i < N; i++){
        // collecting input
        cout << "Enter file name #" << i + 1 << ": " ;
        cin >> classNameArr[i];

        // passing file name to open the file and assign class structure with name and number of students - also builds dynamic array for students and files
        openFile(classNameArr[i], classArr[i], studentArr[i]);

        // updating struct class with dynamic array
        classArr[i].list = studentArr[i];

    }

    // Processing
    while (run){
        // collecting users choice
        int choice = menuChoice();
        
        // processing users choice
        switch (choice){
            case 1: {
                option1(classArr);
                break;
            }
            case 2: {
                option2(classArr);
                break;
            }
            case 3: {
                option3(classArr);
                break;
            }
            case 4: {
                option4(classArr);
                break;
            }
            case 5: {
                option5(run, studentArr);
                break;
            }
        }


    }
    

}

// helper functions definition:
// opens files/ assigns class name and number of students in the class struct and builds and fills a dynamic array of students 
void openFile(string f, course& c, Student*& s){
    // opening file
    fstream classFile;
    classFile.open(f);

    if(classFile.fail()){
        cout << "file error, failed to open" << endl;
        exit(1);
    }

    // filling class struct 
    classFile >> c.title >> c.number_of_students;
    
    // setting up dynamic student array
    s = new Student[c.number_of_students] {};

    // filling dynamic array with student profile
    for (int i = 0; i < c.number_of_students; i++){
        // temp variables for holding student profile
        int id = 0;
        string n = " ";
        int sc = 0;

        // filling temp var with data from file
        classFile >> id >> n >> sc;
        
        s[i] = Student(id, n, sc);
    }
    
}

// presents user with the menu and collects users choice
int menuChoice(){
    int choice = 0;

    cout << endl << string(17, '=') << " Menu " << string(17, '=')
        << "\n1. Show all course lists (sorting)"
        << "\n2. List of students who take all courses"
        << "\n3. List of students who take two courses"
        << "\n4. Print out top three scores for each course"
        << "\n5. Exit"
        << "\n-----> Select : ";

    cin >> choice;
    cout << endl;
    return choice;
}

// proccessing the users first choice - print and sort array for each file
void option1(course c[]){
    // loop through course arr - sorts student array and prints data in each class
    for(int i = 0; i < N; i++){

        // sorting dynamic array of students 
        for (int j = 0; j < c[i].number_of_students; j++){
            for (int k = j + 1; k < c[i].number_of_students; k++ ){
                if (c[i].list[j].getID() > c[i].list[k].getID()){
                    Student temp = c[i].list[j];
                    c[i].list[j] = c[i].list[k];
                    c[i].list[k] = temp;
                }
            }
        }
        // displaying header of each class
        cout << string(10, '=') << " " << c[i].title << " " << string(10, '=') << endl << endl;

        // displaying each student
        for(int j = 0; j < c[i].number_of_students; j++){
            cout << c[i].list[j];
        }

        cout << endl;
    }
}

// processing second opiton - prints list of all students taking all course
void option2(course c[]){
    // local variables to track number of students in all three
    int studCount = 0;
    student3Course* studList = nullptr;

    // takes first class of students and check ea student for presence in other classes
    for (int i = 0; i < c[0].number_of_students; i++){
        bool class2Match = false;
        bool class3Match = false;
        int count1 = 0;
        int count2 = 0;
        string currentStudent = c[0].list[i].getName();
        student3Course currStud = {c[0].list[i].getID(), currentStudent, c[0].list[i].getScore(), 0, 0};

        // checking for matches in class 2
        while (!class2Match && count1 < c[1].number_of_students){
            if (currentStudent == c[1].list[count1].getName()){
                currStud.score2 = c[1].list[count1].getScore();
                class2Match = true;
            }else{
                count1 ++;
            }
        }

        // checking for matches in class 3 if theres a match in class 2
        if (class2Match){
            while (!class3Match && count2 < c[2].number_of_students){
                if (currentStudent == c[2].list[count2].getName()){
                    currStud.score3 = c[2].list[count2].getScore();
                    class3Match = true;
                }else{
                    count2++;  
                }
            }
        }

        // saving student if attending all three class/ resizing dynamic array/ incrementing count
        if (class2Match && class3Match){
            studList = resize3Course(studList, studCount);
            studList[studCount] = currStud;
            studCount++;
        }
    }

    if(studCount == 0){
        cout << "There are no students who take all three courses." << endl;
        delete [] studList;
        return;
    }

    // sorting students
    sort3Course(studList, studCount);

    // printing students and message to user
    cout<< "There are " << studCount << " students who take 3 courses" << endl
        << string(45, '-') << endl;
    print3Course(studList, c, studCount);     

    delete[] studList;
}

// resize array of students who take 3 courses
student3Course* resize3Course(student3Course* s, int a){
    int num = a + 1;
    student3Course* temp = new student3Course[num];
    
    // sets up dynamic array if first iteration otherswise copys over data
    if(s != nullptr){
        for (int i = 0 ; i < a; i++){
            temp[i] = s[i];
        }  
        delete[] s; 
    }
    return temp;
}

// sorts array of struct of students that take all three courses in ascending order by ID
void sort3Course(student3Course*& s, int size){
    student3Course temp;

    for (int i = 0; i < size - 1; i++){
        for (int j = i + 1; j < size; j++){
            if (s[i].ID > s[j].ID){
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

// prints array of struct of students that take all three courses
void print3Course(student3Course* s, course c[], int size ){
      for(int i = 0; i < size; i++){
        cout << setw(8) << s[i].ID <<setw(10) << s[i].name 
        << setw(8) << c[0].title << "(" << s[i].score1 << ")" 
        << setw(8) << c[1].title << "(" << s[i].score2 << ")"
        << setw(8) << c[2].title << "(" << s[i].score3 << ")" << endl;
    }
}

// processing third option - prints list of students who take only 2 course but not three
void option3(course c[]){
    
    // check first and second for match 
    check2Course(c, 0, 1, 2);

    // check second and third for match 
    check2Course(c, 1, 2, 0);

    // check first and third for match
    check2Course(c, 0, 2, 1);
}

// checks if student is in only two classes - first two ints are for matches, last int is class thats exlcuded
void check2Course(course course[], int a, int b, int c){
    // local variables to track number of students in all three
    int studCount = 0;
    student2Course* studList = nullptr;

    // takes first class of students and check ea student for presence in other classes
    for (int i = 0; i < course[a].number_of_students; i++){
        bool class2Match = false;
        bool class3Match = false;
        int count1 = 0;
        int count2 = 0;
        string currentStudent = course[a].list[i].getName();
        student2Course currStud = {course[a].list[i].getID(), currentStudent, course[a].list[i].getScore(), 0};

        // checking for matches in class 2
        while (!class2Match && count1 < course[b].number_of_students){
            if (currentStudent == course[b].list[count1].getName()){
                currStud.score2 = course[b].list[count1].getScore();
                class2Match = true;
            }else{
                count1 ++;
            }
        }

        // checking for matches in class 3 if theres a match in class 2
        if (class2Match){
            while (!class3Match && count2 < course[c].number_of_students){
                if (currentStudent == course[c].list[count2].getName()){
                    class3Match = true;
                }else{
                    count2++;  
                }
            }
        }

        // saving student if attending all three class/ resizing dynamic array/ incrementing count
        if (class2Match && !class3Match){
            studList = resize2Course(studList, studCount);
            studList[studCount] = currStud;
            studCount++;
        }
    }

    if(studCount == 0){
        cout << "There are no students who take both " << course[a].title << " and " <<  course[b].title << " only." << endl;
        delete [] studList;
        return;
    }

    // sorting students in only 2 given courses
    sort2Course(studList, studCount);
    // printing students in only 2 given courses
    print2Course(studList, course[a].title, course[b].title, studCount);

    delete [] studList;
}


// resizes array of students that take two course
student2Course* resize2Course(student2Course* s, int a){
    int num = a + 1;
    student2Course* temp = new student2Course[num];

    // sets up dynamic array if first iteration otherswise copys over data
    if(s != nullptr){
        for (int i = 0 ; i < a; i++){
            temp[i] = s[i];
        }  
        delete[] s; 
    }
    return temp;
}


// sorts array of struct of students that take two course by ID in ascending order
void sort2Course(student2Course*& s, int size){
    student2Course temp;

    for (int i = 0; i < size - 1; i++){
        for (int j = i + 1; j < size; j++){
            if (s[i].ID > s[j].ID){
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

// prints array of struct of students that take two course
void print2Course(student2Course* s, string c1, string c2, int size){
    cout<< "There are " << size << " students who take " << c1 << " and " << c2 << endl;
    cout<< string(48, '-') << endl;

    for(int i = 0; i < size; i++){
        cout << setw(8) << s[i].ID <<setw(10) << s[i].name 
        << setw(8) << c1 << "(" << s[i].score1 << ")" 
        << setw(8) << c2 << "(" << s[i].score2 << ")" << endl;
    }

    cout<< endl;
}

// finding top three scores/ print in ascending order of id 
void option4(course c[]){
    for(int i = 0; i < N; i++){
        findHighScore(c[i]);
    }
}

// finds the high scores when passed a single course struct
void findHighScore(course c){
    // stores top three scores
    int topThree [3] = {0};
    int size = c.number_of_students;

    // find top three scores
    for (int i = 0; i < size; i++){
        int currentScore = c.list[i].getScore();

        // adjusting array as long as not already present
        if (currentScore == topThree[0] || currentScore == topThree[1] || currentScore == topThree[2]){
        }
        else if (currentScore > topThree[0]){
            topThree[2] = topThree[1];
            topThree[1] = topThree[0];
            topThree[0] = currentScore;
        } else if (currentScore > topThree[1]){
            topThree[2] = topThree[1];
            topThree[1] = currentScore;
        }else if(currentScore > topThree[2]){
            topThree[2] = currentScore;
        }

    }

    // finding students with top three scores and prints
     cout << "[ " << c.title << " Top Three Scores ]" << endl;
    for (int i = 0; i < 3; i++){
        int place = i + 1;
        cout << place <<".  " << topThree[i] << endl;
        findStud(c, topThree[i]);
    }
    cout << endl;

}

// finds students with a given score and sorts in ascending order and prints array
void findStud(course c, int score){
    int count = 0;
    studentHighScore* names = nullptr;

    for (int i = 0; i < c.number_of_students; i++){
        if (c.list[i].getScore() == score){
            studentHighScore temp = {c.list[i].getID(), c.list[i].getName()};
            names = resizeHighScore(names, count);
            names[count] = temp;
            count ++;
        }
    }

    // sorting array of students 
    for (int i = 0; i < count - 1; i++){
        for (int j = i + 1; j < count; j++){
            if (names[i].ID > names[j].ID){
                studentHighScore temp = names[i];
                names[i] = names[j];
                names[j] = temp;
            }
        }
    }

    // printing students
    for (int i = 0; i < count; i++){
        cout << setw(10) << names[i].ID << setw(10) << names[i].name << endl;
    }

    delete[] names;
}

//dynamic resizes array of students with a high score
studentHighScore* resizeHighScore(studentHighScore* s, int c){
    int num = c + 1;
    studentHighScore* temp = new studentHighScore[num];
    
    // sets up dynamic array if first iteration otherswise copys over data
    if(s != nullptr){
        for (int i = 0 ; i < c; i++){
            temp[i] = s[i];
        }  
        delete[] s; 
    }
    return temp;
}

// ends program
void option5(bool &b, Student* s[]){
    b = false;

    for (int i = 0; i < N; i++){
        delete[] s[i];
        s[i] = nullptr;
    }

}






