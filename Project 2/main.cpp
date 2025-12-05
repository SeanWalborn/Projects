/* 
Project 1
Name: Sean Walborn 
ID: 10763229
Submission Date: 12/05/25
*/

/*
    This project collects two files from the user. 
*/ 

#include <iostream>
#include <fstream>
// #include "Book.h"
// #include "HistoryBook.h"
// #include "Novel.h"
// #include "ChildrenBook.h"
// #include "ComputerBook.h"
// #include "Person.h"
// #include "Staff.h"
// #include "Student.h"
// #include "Adult.h"

using namespace std;

// helper function declaration
void displayMenu();
void openBookFile();
void openPersonFile();
void menu1();
void menu2();
void menu3();
void menu4();
void menu5();


int main(){
    // Variables
    string personFileName, bookFileName;
    int choice;


    // Collecting file input
    cout << "Enter file name 1: ";
    cin >> bookFileName;
    cout << "Enter file name 2: ";
    cin >> personFileName;
    
    // Opening files
    openBookFile();
    openPersonFile();

    // setting up library

    // Displaying menus and executing user choic
    while(true){
        displayMenu();
        cin >> choice;

        switch(choice){
            case 1:
                menu1();
                break;
            case 2:
                menu2();
                break;
            case 3:
                menu3();
                break;
            case 4:
                menu4();
                break;
            case 5:
                menu5();
                break;
            case 6:
                return 0;
        }
        
    }
    
}

// Helper Function Implementation
void displayMenu(){
        cout << endl << string(45, '-') << endl
        << string(20, ' ') << "MENU" << string(20, ' ') << endl
        << string(45, '-') << endl
        << " 1. Search a book\n"
        << " 2. Show my information\n"
        << " 3. Rent a book\n"
        << " 4. Return a book\n"
        << " 5. Show all books\n"
        << " 6. Exit the programs\n\n"
        << "Choose one menu [1-6]:";
}
void menu1(){

}
void menu2(){

}
void menu3(){

}
void menu4(){

}
void menu5(){

}


