// File Name: Students.cpp
//
// Author: Jayce Jones
// Date: 09/17/16
// Assignment Number: 1
// CS 3358: Fall 2016
// Instructor: CJ Hwang
//
// Represents a student record list
// Includes a students ID, name, GPA, and address
// Supports adding and displaying student records to an array and
// a list, both unsorted

#include <string>
#include "StudentList.h"

//***********************************************************
// Student: Constructs a list with default student info
//***********************************************************

Student::Student()
{
    studentID = 0;
    studentName = "";
    studentGPA = 0.0;
    studentAddress = "";
}

//***********************************************************
// Product: Constructs a list given an ID, name, GPA,
//          and location.
//***********************************************************
Student::Student(int newID, string newName, double newGPA,
                 string newAddress)
{
    studentID = newID;
    studentName = newName;
    studentGPA = newGPA;
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

//getGPA: accessorFunction to get a students name
double Student::getGPA()
{
    return studentGPA;
}

//getAddress: accessorFunction to get a students address
string Student::getAddress()
{
    return studentAddress;
}

// setLocator: mutator function to set a students ID
void Student::setID(int newID)
{
    studentID = newID;
}

//setName: mutator fucntion to set a students name
void Student::setName(string newName)
{
    studentName = newName;
}

//setGPA: mutator funtion to set a students GPA
void Student::setGPA(double newGPA)
{
    studentGPA = newGPA;
}

//setAddress: mutator function to set a students address
void Student::setAddress(string newAddress)
{
    studentAddress = newAddress;
}
