// File Name: StudentDriver.cpp
//
// Author: Jayce Jones
// Date: 09/23/16
// Assignment Number: 2
// CS 3358: Fall 2016
// Instructor: CJ Hwang
//
// Represents a student record list
// Includes a students ID, name, GPA, and address
// Supports adding and displaying student records to an array and
// a list, both unsorted

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>

#include "StudentList.h"

using namespace std;

int main()
{
    //Creating and displaying unsorted array (Task A)
    Student records[10]; //Creating student records array
    srand(unsigned(time(NULL)));
    
    for (int i=0; i<10; i++)
    {
        int randomNumber;
        randomNumber = rand()% 1000000+1;
        records[i].setID(randomNumber);
    }
    
    records[0].setName("Arya");
    records[0].setGPA(2.9);
    records[0].setAddress("Braavos");
    
    records[1].setName("Podrick");
    records[1].setGPA(3.9);
    records[1].setAddress("Silverhill");
    
    records[2].setName("Eddard");
    records[2].setGPA(2.5);
    records[2].setAddress("Winterfell");
    
    records[3].setName("Jorah");
    records[3].setGPA(1.5);
    records[3].setAddress("Volantis");
    
    records[4].setName("Dany");
    records[4].setGPA(3.4);
    records[4].setAddress("Mereen");
    
    records[5].setName("Theon");
    records[5].setGPA(1.2);
    records[5].setAddress("Pyke");
    
    records[6].setName("Davos");
    records[6].setGPA(2.6);
    records[6].setAddress("White Harbor");
    
    records[7].setName("Tyrion");
    records[7].setGPA(3.9);
    records[7].setAddress("Pentos");
    
    records[8].setName("Myrcella");
    records[8].setGPA(2.9);
    records[8].setAddress("Sunspear");
    
    records[9].setName("Cersi");
    records[9].setGPA(2.7);
    records[9].setAddress("Kings Landing");
    
    //Displaying unsorted array
    cout << "Unsorted array: " << endl;
    cout << "ID     " << "Name     " << "GPA   " << "Address     " << endl;
    for (int i=0; i<10; i++)
    {
        cout << left << setw(7) << records[i].getID() << setw(9)
        << records[i].getName() << setw(6) << records[i].getGPA()
        << setw(4) << records[i].getAddress() << endl;
    }
    cout << endl;
    
    //Transfering array to linked list(Task B)
    StudentList listings;   //To hold student listings
    for (int i=0; i<10; i++)
    {
        listings.appendStudent(records[i]);
    }
    
    listings.displayRecords();
    cout << endl;
    
    //Creating second linked list of students, sorted by ID(Taks F)
    StudentList listings2;
    for (int i=0; i<10; i++)
    {
        listings2.insertStudent(records[i]);
    }
    
    listings2.displayRecords();
    
    //Remove a student record (Task G)
    int badStudent; //The student whose record is to be removed
    cout << endl;
    cout << "Enter the ID of the student whose record is to removed: ";
    cin >> badStudent;
    cout << endl;
    
    bool delResult;
    delResult = listings2.removeStudent(badStudent);
    if (delResult == true)
    {
       cout << "Student " << badStudent << " removed" << endl;
       cout << endl;
       listings2.displayRecords();
       cout << endl;
    }
    else
    {
        cout << "That student record does not exist" << endl;
        return 0;
    }
    
    //Insert a new student record(Task G)
    Student newStudent;
    newStudent = Student((rand()% 1000000+1),"Lancel",2.1, "Darry");
    listings2.insertStudent(newStudent);
    cout << "New student " << newStudent.getID() << " added " << endl;
    cout << endl;
    listings2.displayRecords();
    return 0;
}
