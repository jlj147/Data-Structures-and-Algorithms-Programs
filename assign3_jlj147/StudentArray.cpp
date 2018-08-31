// File Name: StudentArray.cpp
//
// Author: Jayce Jones
// Date: 09/29/16
// Assignment Number: 3
// CS 3358: Fall 2016
// Instructor: CJ Hwang
//
// Represents a student record list
// Includes a students ID, name, avearge test score, and address
// Takes the student list and creates a stack, pops from stack
// and displays the list as if it is a stack

#include <string>
#include "StudentStack.h"
//***********************************************************
// Student: Constructs an array with default student info
//***********************************************************

StudentArray::StudentArray()
{
    studentID = 0;
    studentName = "";
    studentAverage = 0.0;
    studentAddress = "";
    studentPointer = new int[10];
}

//***********************************************************
// Student: Constructs an array given an ID, name, GPA,
//          and location.
//***********************************************************
StudentArray::StudentArray(int newID, string newName, double average,
                           string newAddress,int testScores)
{
    studentID = newID;
    studentName = newName;
    studentAverage = average;
    studentAddress = newAddress;
    *studentPointer = testScores;
}

// setID: accessor function to set a students ID
void StudentArray::setID(int newID)
{
    studentID = newID;
}
//setName: accessorFunction to set a students name
void StudentArray::setName(string newName)
{
    studentName = newName;
}
//setAverage: accessorFunction to set a student average
void StudentArray::setAverage(double average)
{
    studentAverage = average;
}

//setAddress: accessorFunction to set a students address
void StudentArray::setAddress(string newAddress)
{
    studentAddress = newAddress;
}

//setPointer: accessorFunction to set a pointer to a students
//            testScores
void StudentArray::setPointer(int testScores)
{
    studentPointer = &testScores;
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

//getAverage: accessorFuction to return a students average
double StudentArray::getAverage()
{
    return studentAverage;
}

//getAddress: accessorFunction to return a students address
string StudentArray::getAddress()
{
    return studentAddress;
}

