// File Name: StudentArray.cpp
//
// Author: Jayce Jones
// Date: 10/29/16
// Assignment Number: 6A
// CS 3358: Fall 2016
// Instructor: CJ Hwang
//
// Represents a student record list hash table
// Includes a students ID and name
// Supports searching through list for a students name

#include <string>
#include "StudentArray.h"

//***********************************************************
// Student: Constructs a list with default student info
//***********************************************************

StudentArray::StudentArray()
{
    studentID = 0;
    studentName = "";
}

//***********************************************************
// Product: Constructs a list given an ID, name, GPA,
//          and location.
//***********************************************************
StudentArray::StudentArray(int newID, string newName)
{
    studentID = newID;
    studentName = newName;
}

// getID: accessor function to return a students ID
int StudentArray::getID()
{
    return studentID;
}
//getName: accessorFunction to return a students name
string StudentArray::getName()
{
    return studentName;
}

// setLocator: mutator function to set a students ID
void StudentArray::setID(int newID)
{
    studentID = newID;
}

//setName: mutator fucntion to set a students name
void StudentArray::setName(string newName)
{
    studentName = newName;
}
