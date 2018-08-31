// File Name: Student.cpp
//
// Author: Jayce Jones
// Date: 10/08/16
// Assignment Number: 4
// CS 3358: Fall 2016
// Instructor: CJ Hwang
//
// Represents a student record list
// Includes a students ID, name, avearge test score, and address
// Takes the student array, transfers it to a list and then to a stack
// creates a stack, pops from stack and displays the list as if it is a stack

#include <string>
#include <iostream>
#include <ctime>
#include "StudentStack.h"

//***********************************************************
// Student: Constructs a list with default student info
//***********************************************************
Student::Student()
{
    studentID = 0;
    studentName = "";
    studentAverage = 0.0;
    studentAddress = "";
}

//***********************************************************
// Student: Constructs a list given an ID, name, GPA,
//          and location.
//***********************************************************
Student::Student(int newID, string newName, double newAverage, string newAddress)
{
    studentID = newID;
    studentName = newName;
    studentAverage = newAverage;
    studentAddress = newAddress;
}

// setID: accessor function to set a students ID
void Student::setID(int newID)
{
    studentID = newID;
}
//setName: accessorFunction to set a students name
void Student::setName(string newName)
{
    studentName = newName;
}

//setAverage: accessorFunction to set a student average
void Student::setAverage(double newAverage)
{
    srand(unsigned(time(NULL)));
    int total=0;
    for(int i=0; i<10; i++) //Set student scores
    {
        studentScores[i] = (rand()%100+1);
        total += studentScores[i];
    }
    studentAverage = (total/10.0);
    scores = studentScores; //Pointing at array
    studentAverage = newAverage;
}

//setAddress: accessorFunction to set a students address
void Student::setAddress(string newAddress)
{
    studentAddress = newAddress;
}

// getID: accessor function to return a students ID
int Student::getID()
{
    return studentID;
}
//getName: accessorFunction to return a students name
string Student::getName()
{
    return studentName;
}

//getAverage: accessorFuction to return a students average
double Student::getAverage()
{
    return studentAverage;
}

//getAddress: accessorFunction to return a students address
string Student::getAddress()
{
    return studentAddress;
}

