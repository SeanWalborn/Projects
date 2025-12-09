/* 
Project 1
Name: Sean Walborn 
ID: 10763229
Submission Date: 12/05/25
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include "Book.cpp"
#include "HistoryBook.cpp"
#include "Novel.cpp"
#include "ChildrenBook.cpp"
#include "ComputerBook.cpp"
#include "Person.cpp"
#include "Staff.cpp"
#include "Student.cpp"
#include "Adult.cpp"

using namespace std;

// struct delcaration
struct BookNode{
    Book* data;
    struct BookNode* link;
};
struct PersonNode{
    Person* data;
    struct PersonNode* link;
};

// helper function declaration
void displayMenu();
void openBookFile(BookNode* (&library)[4], string filename);
void insertBook(BookNode*& head, Book* b);
void openPersonFile(PersonNode* (&persons)[3], string filename);
void insertPerson(PersonNode*& head, Person* p);
void menu1(BookNode* library[4]); //search for books
void menu2(PersonNode* persons[3], BookNode* library[4]); // display user information
void menu3(BookNode* (&library)[4], PersonNode* (&persons)[3]); // rent a book 
void menu4(BookNode* (&library)[4], PersonNode* (&persons)[3]); // return a book
void menu5(BookNode* library[4]); // displays all books
void menu6(BookNode* (&library)[4], PersonNode* (&persons)[3]); 


int main(){
    // Variables
    string personFileName, bookFileName;
    int choice;
    BookNode* library[4] = {nullptr}; // stores 4 heads for differnet books linked lists
    PersonNode* persons[3] = {nullptr}; // stores 3 heads for differnt persons linked lists


    // Collecting file input
    cout << "Enter file name 1: ";
    cin >> bookFileName;
    cout << "Enter file name 2: ";
    cin >> personFileName;
    
    // Opening files and creating linked lists
    openBookFile(library, bookFileName);
    openPersonFile(persons, personFileName);

    // Displaying menus and executing user choic
    while(true){
        displayMenu();
        cin >> choice;

        switch(choice){
            case 1:
                menu1(library);
                break;
            case 2:
                menu2(persons, library);
                break;
            case 3:
                menu3(library, persons);
                break;
            case 4:
                menu4(library, persons);
                break;
            case 5:
                menu5(library);
                break;
            case 6:
                menu6(library, persons);
                return 0;
        }
        
    }
    
}

// Helper Function Implementation
void openBookFile(BookNode* (&library)[4], string filename){
    
    
    // opening file
    ifstream bookFile; 
    bookFile.open(filename);

    // chekcing if file opened
    if (bookFile.fail()){
        cout << "file errors" << endl;
        exit(1);
    }

    // filling linked lists
    string line;
    while(getline(bookFile, line)){
        // temp varible
        int code, available, rented, age, publish_year;
        string title, publisher, author;
        Book* temp = nullptr;

        // setting up string stream from line
        stringstream ss(line);
        string word;
        vector<string> splitLine;

        // filling vector
        while(ss >> word){
            splitLine.push_back(word);
        }
        
        // loading variables 
        code = stoi(splitLine[0]);
        title = splitLine[1];
        available = stoi(splitLine[3]);
        rented = stoi(splitLine[4]);

        // checking book type and creating object
        if (code > 1000 && code < 2001){ 
            age = stoi(splitLine[2]);
            temp = new ChildrenBook(code, title, age, available, rented);
            insertBook (library[0], temp);

        }else if(code > 2000 && code < 3001){
            publisher = splitLine[2];
            temp = new ComputerBook(code, title, publisher, available, rented);
            insertBook (library[1], temp);

        }else if(code > 3000 && code < 4001){
            publish_year = stoi(splitLine[2]);
            temp = new Novel(code, title, publish_year, available, rented);
            insertBook (library[2], temp);

        }else if (code > 4000 && code < 5001){
            author = splitLine[2];
            temp = new HistoryBook(code, title, author, available, rented);
            insertBook (library[3], temp);
        }

        temp = nullptr;

    }
}

void insertBook(BookNode*& head, Book* b){
    // temp node to iterate
    BookNode* temp = head;

    // setting up next node
    BookNode* newNode = new BookNode;
    newNode->data = b;
    newNode->link = nullptr;

    // checking if head is empty or new node should replace head
    if (head == nullptr || head->data->getCode() > newNode->data->getCode() ){
        newNode -> link = head;
        head = newNode;
        return;
    }   

    // finding correct spot for node
    while(temp->link != nullptr && temp->link->data->getCode() < newNode->data->getCode()){
        temp = temp->link; 
    }

    // inserting node
    newNode->link = temp->link;
    temp->link = newNode;

    newNode = nullptr;
    temp = nullptr;

}

void openPersonFile(PersonNode* (&persons)[3], string filename){
    // opening file
    ifstream personFile; 
    personFile.open(filename);

    // chekcing if file opened
    if (personFile.fail()){
        cout << "file errors" << endl;
        exit(1);
    }

    // filling linked lists
    string line;
    while(getline(personFile, line)){
        // temp varible
        int id, count, *code;
        string name;
        Person* temp = nullptr;

        // setting up string stream from line
        stringstream ss(line);
        string parseLine[3];

        // push id/name/rentals to an array
        for (int i = 0; i < 3; i++){
            ss >> parseLine[i];
        }

        // loading variables 
        id = stoi(parseLine[0]);
        name = parseLine[1];
        count = stoi(parseLine[2]);
       

        // checking person role and creating object
        if (id < 101){ // staff
           code = new int[3]{0};
           // adding book codes
           for (int i = 0; i < count; i++){
                int temp;
                ss >> temp;
                code[i] = temp;
           }
           sort(code, code + count);
           temp = new Staff(id, name, count, code);
           insertPerson(persons[0], temp);
            
        }else if(id > 100 && id < 301){ // student
            code = new int[2]{0};
            // adding book codes
            for (int i = 0; i < count; i++){
                int temp;
                ss >> temp;
                code[i] = temp;
            }
            sort(code, code + count);
            temp = new Student(id, name, count, code);
            insertPerson(persons[1], temp);

        }else { // adult
            code = new int[4]{0};
            // adding book codes
            for (int i = 0; i < count; i++){
                int temp;
                ss >> temp;
                code[i] = temp;
            }
            sort(code, code + count);
            temp = new Adult(id, name, count, code);
            insertPerson(persons[2], temp);
        }

        code = nullptr;
        temp = nullptr;
    }

   
}

void insertPerson(PersonNode*& head, Person* p){
    // temp node to iterate
    PersonNode* temp = head;

    // setting up next node
    PersonNode* newNode = new PersonNode;
    newNode->data = p;
    newNode->link = nullptr;

    // checking if head is empty or new node should replace head
    if (head == nullptr || head->data->getId() > newNode->data->getId() ){
        newNode -> link = head;
        head = newNode;
        return;
    }   

    // finding correct spot for node
    while(temp->link != nullptr && temp->link->data->getId() < newNode->data->getId()){
        temp = temp->link; 
    }

    // inserting node
    newNode->link = temp->link;
    temp->link = newNode;

    newNode = nullptr;
    temp = nullptr;
}

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
void menu1(BookNode* library[4]){
    // variables
    string bookTitle = "";
    Book* searchBook = nullptr;
    bool found = false;

    // colleting book title
    cout << "\nEnter book title: "; 
    cin >> bookTitle;

    // finding book 
    try{
        
        // searching each linked list
        for(int i = 0; i < 4; i++){
            BookNode* temp = library[i];
            while(temp != nullptr){
                if (temp->data->getTitle() == bookTitle){
                    found = true;
                    searchBook = temp->data;
                    break;
                }else{
                    temp = temp->link;
                }
            }
            if(found) break;
        }

        if(!found){
            throw bookTitle;
        }
        // formating title
        string title = searchBook->getTitle();
        replace(title.begin(), title.end(), '_', ' ');

        // displaying information
        cout << endl << left << setw(15) << "Code" << ": " << searchBook->getCode() << endl
            << left << setw(15) << "Title" << ": " << title << endl; 

        // determine book type and print correct varaible
        int code = searchBook->getCode();
        if (code > 1000 && code < 2001){ 
            cout << left << setw(15) << "Age" << ": " << searchBook->getAge() << endl;
        }else if(code > 2000 && code < 3001){
            string publisher = searchBook->getPublisher();
            replace(publisher.begin(), publisher.end(), '-', ' ');
            cout << left << setw(15) << "Publisher" << ": " << publisher << endl;
        }else if(code > 3000 && code < 4001){
            cout << left << setw(15) << "Publish Year" << ": " << searchBook->getPublishYear() << endl;
        }else if (code > 4000 && code < 5001){
            cout << left << setw(15) << "Author" << ": " << searchBook->getAuthor() << endl;
        }
         
        // finish display
        cout << left << setw(15) << "Available" << ": " << searchBook->getAvailable() << endl
            << left << setw(15) << "Rented " << ": " << searchBook->getRented() << endl;

    }catch(string bookTitle){
        cout << "The book '" << bookTitle << "' does not exist.\n";
        return;
    }

}
void menu2(PersonNode* persons[3], BookNode* library[4]){
    // variable
    int id;
    bool found = false;
    Person* searchResult = nullptr;

    // collecting id
    cout << endl << "Enter your id: ";
    cin >> id;

    // seraching for id
    try{
        // searching each linked list for id
        for(int i = 0; i < 3; i++){
            PersonNode* temp = persons[i];
            while(temp != nullptr){
                if (temp->data->getId() == id){
                    found = true;
                    searchResult = temp->data;
                    break;
                }else{
                    temp = temp->link;
                }
            }
            if(found) break;
        }

        if (!found){
            throw id;
        }
        
        // displaying user information
        cout << endl << "You are '" << searchResult->getName() << "'. You borrowed " << searchResult->getCount() << " book(s).\n";
        // retrieving book names
        int* bookCode = searchResult->getCode();
        
        // finding book title and displaying result
        for(int i = 1; i < searchResult->getCount()+1; i++){
            string bookTitle;
            // searching each linked list for book
            for(int j = 0; j < 4; j++){
                bool found = false;
                BookNode* temp = library[j];
                while(temp != nullptr){
                    if (temp->data->getCode() == bookCode[i-1]){
                        bookTitle = temp->data->getTitle();
                        found = true;
                        break;
                    }else{
                        temp = temp->link;
                    }
                }
                if(found){
                    temp = nullptr;
                    break;
                }
            }
            replace(bookTitle.begin(), bookTitle.end(), '_', ' ');
            // displaying each book
            cout << i << ". " << bookTitle << " (" << bookCode[i-1] << ")" << endl;
        }

        
    }catch(int id){
        cout << " ID " << id << " does not exist" << endl;
    }
    searchResult = nullptr;
    
}
void menu3(BookNode* (&library)[4], PersonNode* (&persons)[3]){
    // variable
    int id = 0;
    int booksAllowed = 0; 
    int booksCheckedOut = 0;
    string bookTitle;
    bool bookFound = false;
    bool idFound = false;
    Book* bookResult = nullptr;
    Person* personResult = nullptr;
    int* bookList = nullptr;

    

    // collecting input
    cout << "\nEnter your id: ";
    cin >> id;
    cout << "Enter book title: ";
    cin >> bookTitle;
    
    // finding ID
    for(int i = 0; i < 3; i++){
        PersonNode* temp = persons[i];
        while(temp != nullptr){
            if (temp->data->getId() == id){
                idFound = true;
                personResult = temp->data;
                break;
            }else{
                temp = temp->link;
            }
        }
        if(idFound){
            temp = nullptr;
            break;
        } 
    }

    // finding book
    for(int i = 0; i < 4; i++){
        BookNode* temp = library[i];
        while(temp != nullptr){
            if (temp->data->getTitle() == bookTitle){
                bookFound = true;
                bookResult = temp->data;
                break;
            }else{
                temp = temp->link;
            }
        }
        if(bookFound){
            temp = nullptr;
            break;
        }
    }


    // determining number of books allowed for person 
    bookList = personResult->getCode();
    if (id > 100 && id < 301){
        booksAllowed = 2; // student 
    }else if( id > 0 && id < 101){
        booksAllowed = 3; // staff
    }else if (id > 300 && id < 1001){ //adult
        booksAllowed = 4;
    }

    // setting number of books checked out
    booksCheckedOut = personResult->getCount();

    

    // check if maxed out rentals and availbiltiy
    try{
        // checking book available
        if (bookResult->getAvailable() == 0){
            throw bookTitle;
        }

        // checking number of books person has checked out
        if (booksAllowed == booksCheckedOut){
            throw booksAllowed;
        }

        // updating book in person list
        int count = personResult->getCount() + 1;
        personResult->setCount(count);
        bookList[booksCheckedOut] = bookResult->getCode();
        booksCheckedOut++;
        sort(bookList, bookList + booksCheckedOut);
        
        // updating rented and available
        int available = bookResult->getAvailable() - 1;
        bookResult->setAvailable(available);
        int rented = bookResult->getRented() + 1;
        bookResult->setRented(rented);

        //displaying results to user
        string title = bookResult->getTitle();
        replace (title.begin(), title.end(), '_', ' ');
        cout << endl << "You are '" << personResult->getName() << "'. The book '" << title << "' is available.\n"
            << "Rent succeed. Now you borrowed " << booksCheckedOut << " book(s).\n";
        
        // finding book titles and displaying result
        for(int i = 1; i < personResult->getCount()+1; i++){
            string bookTitle;
            // searching each linked list for book
            for(int j = 0; j < 4; j++){
                bool found = false;
                BookNode* temp = library[j];
                while(temp != nullptr){
                    if (temp->data->getCode() == bookList[i-1]){
                        bookTitle = temp->data->getTitle();
                        found = true;
                        break;
                    }else{
                        temp = temp->link;
                    }
                }
                if(found) {
                    temp = nullptr;
                    break;
                }
            }
            replace(bookTitle.begin(), bookTitle.end(), '_', ' ');
            // displaying each book
            cout << i << ". " << bookTitle << endl;
        }



    }catch(int maxBooks){
        cout << "you cannot excced your rental max of " << maxBooks << endl;
    }
    catch(string title){
        cout << "No copies of " << title << " are available" << endl;
    }

     bookResult = nullptr;
     personResult = nullptr;
     bookList = nullptr;

}
void menu4(BookNode* (&library)[4], PersonNode* (&persons)[3]){
    // variables
    int id, titleCode;
    int booksRented = 0;
    string title;
    Book* bookResult = nullptr;
    Person* personResult = nullptr;
    int* bookList = nullptr;
    bool idFound = false;
    bool bookFound = false;
    bool rented = false;

    // collecting input
    cout << "\nEnter your id: ";
    cin >> id; 
    cout << "Enter book title to return: ";
    cin >> title;

    // finding person
    for(int i = 0; i < 3; i++){
        PersonNode* temp = persons[i];
        while(temp != nullptr){
            if (temp->data->getId() == id){
                idFound = true;
                personResult = temp->data;
                break;
            }else{
                temp = temp->link;
            }
        }
        if(idFound) {
            temp = nullptr;
            break;
        }
    }

    // finding book
    for(int i = 0; i < 4; i++){
        BookNode* temp = library[i];
        while(temp != nullptr){
            if (temp->data->getTitle() == title){
                bookFound = true;
                bookResult = temp->data;
                break;
            }else{
                temp = temp->link;
            }
        }
        if(bookFound) {
            temp = nullptr;
            break;
        }
    }

    // getting book code and list of users rented books
    titleCode = bookResult->getCode();
    bookList = personResult->getCode();
    booksRented = personResult->getCount();


    // verify book was checked out before returning it
    try{
        for(int i = 0; i < booksRented; i++){
            if (titleCode == bookList[i]){
                rented = true;
            }
        }
        
        if(!rented){
            throw title;
        }

        // finding and removing book code
        int end = booksRented -1; // finding index last book
        int temp = bookList[end]; // save last book
        bookList[end] = 0; // removing last book

        for (int i = 0; i < booksRented; i++){
            if(bookList[i] == titleCode){
                bookList[i] = temp; // replacing rented book with last book
            }
        }

        // updating book count in person list
        int count = personResult->getCount() - 1;
        personResult->setCount(count);
        sort(bookList, bookList + count);

        // updating rented and available
        int available = bookResult->getAvailable() + 1;
        bookResult->setAvailable(available);
        int rented = bookResult->getRented() - 1;
        bookResult->setRented(rented); 

        // displaying result
        cout << "\nyou are '" << personResult->getName() << "'. The book '" << title << "' is returned.\n"
            << "Return succeed. now you borrowed " << personResult->getCount() << " book(s)" << endl;

        // finding book titles and displaying result
        for(int i = 1; i < personResult->getCount()+1; i++){
            string bookTitle;
            // searching each linked list for book
            for(int j = 0; j < 4; j++){
                bool found = false;
                BookNode* temp = library[j];
                while(temp != nullptr){
                    if (temp->data->getCode() == bookList[i-1]){
                        bookTitle = temp->data->getTitle();
                        found = true;
                        break;
                    }else{
                        temp = temp->link;
                    }
                }
                if(found) {
                    temp = nullptr;
                    break;
                } 
            }
            replace(bookTitle.begin(), bookTitle.end(), '_', ' ');
            // displaying each book
            cout << i << ". " << bookTitle << endl;
        }


    }catch(string title){
        replace(title.begin(), title.end(), '_', ' ');
        cout << "you did not borrow the book titled " << title << endl; 
    }

    bookResult = nullptr;
    personResult = nullptr;
    bookList = nullptr;
    
}
void menu5(BookNode* library[4]){
    BookNode* temp = library[0];
    
    cout << endl <<  string(14, ' ') << "< Children Book >" << endl;
    cout << string(45, '-') << endl;
    while(temp != nullptr){
        Book* b = temp->data;
        string title = b->getTitle();
        replace(title.begin(), title.end(), '_', ' ');

        cout << b->getCode() 
            << setw(25) << title 
            << setw(4) << b->getAge() 
            << setw(4) << b->getAvailable() 
            << setw(4) << b->getRented() << endl; 
        temp =temp->link;
        b = nullptr;
    }

    temp = library[1];
    cout << endl << string(21,' ') << "< Computer Book >" << endl;
    cout << string(60, '-') << endl;
    while(temp != nullptr){
        Book* b = temp->data;
        string title = b->getTitle();
        replace(title.begin(), title.end(), '_', ' ');

        string publisher = b->getPublisher();
        replace(publisher.begin(), publisher.end(), '-', ' ');

        cout << b->getCode() 
            << setw(25) << title 
            << setw(20) << publisher 
            << setw(4) << b->getAvailable() 
            << setw(4) << b->getRented() << endl; 
        temp =temp->link;
        b = nullptr;
    }

    temp = library[2];
    cout << endl << string(18, ' ') << "< Novel >" << endl;
    cout << string(46, '-') << endl;
    while(temp != nullptr){
        Book* b = temp->data;
        string title = b->getTitle();
        replace(title.begin(), title.end(), '_', ' ');

        cout << b->getCode() 
            << setw(25) << title 
            << setw(6) << b->getPublishYear() 
            << setw(4) << b->getAvailable() 
            << setw(4) << b->getRented() << endl; 
        temp =temp->link;
        b = nullptr;
    }

    temp = library[3];
    cout << endl << string(19, ' ')<< "< History Book >" << endl;
    cout << string(55, '-') << endl;
    while(temp != nullptr){
        Book* b = temp->data;
        string title = b->getTitle();
        replace(title.begin(), title.end(), '_', ' ');

        cout << b->getCode() 
            << setw(25) << title 
            << setw(15) << b->getAuthor() 
            << setw(4) << b->getAvailable() 
            << setw(4) << b->getRented() << endl; 
        temp =temp->link;
        b = nullptr;
    }

    temp = nullptr;
}
void menu6(BookNode* (&library)[4], PersonNode* (&persons)[3]){
    
    // deleteing each book
    for (int i = 0; i < 4; i++){
        BookNode* temp = library[i];
        while(temp != nullptr){
            BookNode* next = temp->link;
            delete temp->data;
            delete temp;
            temp = next;
        }
        library[i] = nullptr;
        temp = nullptr;
    }

    // deleteing each person
    for (int i = 0; i < 3; i++){
        PersonNode* temp = persons[i];
        while(temp != nullptr){
            PersonNode* next = temp->link;
            delete temp->data;
            delete temp;
            temp = next;
        }
        persons[i] = nullptr;
        temp = nullptr;
    }
}


