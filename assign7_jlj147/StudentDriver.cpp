// File Name: StudentDriver.cpp
//
// Author: Jayce Jones
// Date: 11/07/16
// Assignment Number: 7
// CS 3358: Fall 2016
// Instructor: CJ Hwang
//
// Represents a student record list in vector form
// Includes a students ID, name, GPA, and address
// Supports searching for student ID as a way to find the full
// student record
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
#include "Students.h"

using namespace std;

int main()
{
    vector <Student> records(20); //Declaration of records vector
    
    int ID;     //Variable that students ID from input file is stored in
    string name; //Variable that students name from input file is stored in
    float GPA;  //Variable that students GPA from input file is sotred in
    string address; //Variable that students address from input file is stored
    int scores[3]; //Array that students scores from input file are stored in
    
    int count = 0; //Counter to count how many records have been pushed
                   //onto vector
    Student found; //Accessor for accessing the records vector
    
    //Read student records into record vector
    ifstream fin;
    fin.open("records.txt");
    
    if (!fin)
    {
        cout << "Error - File not found" << endl;
        return (0);
    }
    
    //Add student records into vector until there are 20 records
    do
    {
        Student *add = nullptr; //Accessor for adding to the records vector
        
        for (int i=0;i<20;i++)
        {
            while (fin >> ID)
            {
                add = new Student;
                add -> setID(ID);
                records[i].setID(ID);
                cin.get();
                break;
            }
            while (fin >> name)
            {
                add -> setName(name);
                records[i].setName(name);
                cin.get();
                break;
            }
        
            while (fin >> GPA)
            {
                add -> setGPA(GPA);
                records[i].setGPA(GPA);
                cin.get();
                break;
            }
        
            while (fin >> address)
            {
                add -> setAddress(address);
                records[i].setAddress(address);
                cin.get();
                break;
            }
            
            for (int k=0;k<10;k++)
                
            {
                fin >> scores[k];
                add -> setScores(scores);
                records[i].setScores(scores);
            }
            
        records.push_back(*add); //Push back newest record onto vector
        
        add->print();
        count++; //Incriment counter
        }
    }while(count < 20);

    fin.close(); //Stop reading student records into record vector
    cout << endl;
    
    //Display the student record vector
    cout << "Student Vector: " << endl;
    
    for (int j=0;j<20;j++)
    {
        cout << "ID: " << records[j].getID() << endl;
        cout << "Name: " << records[j].getName() << endl;
        cout << "GPA: " << records[j].getGPA() << endl;
        cout << "Address: "<< records[j].getAddress() << endl;
        cout << "Scores: ";
        for (int i=0; i<3;i++)
        {
            cout << records[j].getScores() << " ";
        }
        cout << endl;
        cout << endl;
    }
    
    //Modify the IDs read in from file into random ID numbers
    for (int k=0;k<20;k++)
    {
        int randomNumber;
        randomNumber = rand()% 1000000+1;
        records[k].setID(randomNumber);
    }

    //Bubble Sort to prepare records with new IDs for search
    bool swap;
    Student temp;
        
    do
    {
        swap = false;
        for (int l=0;l<(20-1);l++)
        {
            if (records[l].getID() > records[l+1].getID())
            {
                temp = records[l];
                records[l] = records[l+1];
                records[l+1] = temp;
                swap = true;
            }
        }
    }while (swap); //End bubble sort
    
    //Display the student records with new sorted ID's
    cout << "Display the new student records sorted by ID"
         << "ready to be searched" << endl;
    cout << endl;
    for(int i=0; i<20; i++)
    {
        cout << "ID: " << records[i].getID() << endl;
        cout << "Name: " << records[i].getName() << endl;
        cout << "GPA: " << records[i].getGPA() << endl;
        cout << "Address: "<< records[i].getAddress() << endl;
        cout << "Scores: ";
        for (int j=0; j<3;j++)
        {
            cout << records[i].getScores() << " ";
        }
        cout << endl;
        cout << endl;
    }
    
//****Test Cases****
    
    int foundRecord;//The vector subscript returned from the binary search
    
    //Test Case 1: Search for an ID
    foundRecord = found.binarySearch(records,0,19,records[1].getID());
    cout << "Test Case #1: " << endl;
    found.printVect(records, foundRecord);

    //Test Case 2: Search for a second ID
    foundRecord = found.binarySearch(records,0,19,records[7].getID());
    cout << "Test Case #2: " << endl;
    found.printVect(records, foundRecord);

    //Test Case 3: Search for a third ID
    foundRecord = found.binarySearch(records,0,19,records[13].getID());
    cout << "Test Case #3: " << endl;
    found.printVect(records, foundRecord);
    
    //Test Case 4: Search for the ID at the end of the vector
    foundRecord = found.binarySearch(records,0,19,records[19].getID());
    cout << "Test Case #4: (Search for ID at the end of the vector)" << endl;
    found.printVect(records, foundRecord);
    
    //Test Case 5: Serach for an ID that is not in the vector
    foundRecord = found.binarySearch(records,0,19,711);
    cout << "Test Case #5: (Search for ID that is not in the vector)" << endl;
    found.printVect(records, foundRecord);
    
    return 0;
}
