// File Name: Students.cpp
//
// Author: Jayce Jones
// Date: 11/18/16
// Assignment Number: 8
// CS 3358: Fall 2016
// Instructor: CJ Hwang
//
// Represents a student record list in vector form
// Includes a students ID, name, GPA, and address
// Supports searching for student ID as a way to find the full
// student record
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#include "Students.h"

//***********************************************************
// Student: Constructs a list with default student info
//***********************************************************
Student::Student()
{
    studentID = 0;
    studentName = "";
    studentGPA = 0.0;
    studentAddress = "";
    for (int i=0;i<10;i++)
    {
        scores[i]=0;
    }
}

//***********************************************************
// Student: Constructs a list given an ID, name, GPA,
//          and address and scores
//***********************************************************
Student::Student(int newID, string newName, double newGPA, string newAddress,
                 int newScores[])
{
    studentID=newID;
    studentName=newName;
    studentGPA = newGPA;
    studentAddress = newAddress;
    scorePointer=newScores;
    for (int i=0; i<10; i++)
    {
        scores[i] = newScores[i];
        scorePointer=&scores[i];
    }
    //scorePointer=scores;
}

//***********************************************************
// setID: mutator function to set a students ID
//***********************************************************
void Student::setID(int newID)
{
    studentID = newID;
}

//***********************************************************
// setName: mutator function to set a students name
//***********************************************************
void Student::setName(string newName)
{
    studentName = newName;
}

//***********************************************************
// setGPA: mutator function to set a students GPA
//***********************************************************
void Student::setGPA(double newGPA)
{
    studentGPA = newGPA;
}

//***********************************************************
// setAddress: mutator function to set a students address
//***********************************************************
void Student::setAddress(string newAddress)
{
    studentAddress = newAddress;
}

//***********************************************************
// setScores: mutator function to set a students scores
//***********************************************************
void Student::setScores(int newscores[3])
{
    for (int i = 0; i < 20; i++)
    {
        scores[i] = *newscores;
        scorePointer = scores;
    }
}

//***********************************************************
// getID: accessor function to return a students ID
//***********************************************************
int Student::getID()
{
    return studentID;
}

//***********************************************************
// getName: accessor function to return a students name
//***********************************************************
string Student::getName()
{
    return studentName;
}

//***********************************************************
// getGPA: accessor function to return a students GPA
//***********************************************************
double Student::getGPA()
{
    return studentGPA;
}

//***********************************************************
// getAddress: accessor function to return a students address
//***********************************************************
string Student::getAddress()
{
    return studentAddress;
}

//***********************************************************
// getScores: accessor function to return a students scores
//***********************************************************
int Student::getScores()
{
        return *scorePointer;
}

//*******************************************************************
// print: Displays the information of each student as the record is
//        read in from the file and added to the vector
//*******************************************************************
void Student::print()
{
    cout << "ID: " << studentID << endl;
    cout << "Name: " << studentName << endl;
    cout << "GPA:  " << studentGPA << endl;
    cout << "Address: " << studentAddress << endl;
    cout << "Scores: ";
    for (int i=0; i<10; i++)
    {
        cout << scores[i] << " ";
    }
    cout << endl;
}

//*******************************************************************
// printVect: Dispalys the information for each student stored in the
//            vector, sorted by ID number
//*******************************************************************
void Student::printVect(vector<Student> records, int foundRecord)
{
    if (foundRecord == -1) //When the student recored is not found
    {
        cout << "No student record found" << endl;
    }
    else //Students record is found
    {
        cout << "ID: " << records[foundRecord].getID() << endl;
        cout << "Name: " << records[foundRecord].getName() << endl;
        cout << "GPA: " << records[foundRecord].getGPA() << endl;
        cout << "Address: "<< records[foundRecord].getAddress() << endl;
        cout << "Scores: ";
        for (int j=0; j<10;j++)
        {
            cout << records[foundRecord].getScores() << " ";
        }
        cout << endl;
        cout << endl;
    }
}

//*******************************************************************
// quickSort: Uses the quicksort algorithm to sort records, from
//            records[start] through records[end]
//*******************************************************************
void Student::quickSort(vector<Student>& records, int start, int end)
{
    if (start < end)
    {
        int pivot = partition(records, start, end); //Partition and get the
                                                    //the pivot point
        quickSort(records, start, pivot-1);
        quickSort(records, pivot+1, end);
    }
}

//*******************************************************************
// partition: selects the value in the middle of the array to set as
//            a pivot point. The list is rearranged so all the values
//            less than the pivot are on its and all the values
//            greater than the pivot are on its right
//*******************************************************************
int Student::partition(vector<Student>& records,int start,int end)
{
    int middle = (start+end)/2; //Use the middle value as a pivot
    Student pivot = records[middle];
    swap(records[end],records[middle]); //Move pivot to end
    
    int i = start-1;
    int j = end-1;
    
    while (i<j)
    {
        while (records[i].getID() < pivot.getID())
        {
            i++;
        }
    
        while (records[j].getID() > pivot.getID())
        {
            j--;
        }
    
        if (i<j)
        {
            swap(records[i++],records[j--]);
        }
    }
    
    swap(records[i],records[end]); //Replace pivot
    return i;
}

//****************************************************************
// The binarySearch function performs a recursive binary search
// on a range of elements of an integer array passed into the
// parameter array. The parameter first holds the subscript of
// the range's starting element, and last holds the subscript
// of the range's last element. The parameter value holds the
// search value. If the search value is found, its array
// subscript is returned. Otherwise, −1 is returned indicating
// the value was not in the array.
//****************************************************************
int Student::binarySearch(vector<Student> records, int first, int last,
                          int value)
{
    cout << "The ID being searched for is: " << value << endl;
    cout << endl;
    
    int middle; //Midpoint of search
    
    if (first > last)
    {
        return -1;
    }
    middle = (first+last)/2;
    
    //If index value is in the middle of the list return index record ID
    if (value==records[middle].getID())
    {
        return middle;
    }
    
    //If value is less than middle of the list call binary search and repeat
    //process on lower half of list
    else if (value < records[middle].getID())
    {
        return binarySearch(records, first, middle-1,value);
    }
    
    //Else value is greater than middle of the the list, call binary search
    //and repeat process on upper half of list
    else
    {
        return binarySearch(records, middle+1, last, value);
    }
}
