// File Name: StudentArray.h
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
using namespace std;

class StudentArray
{
private:
    int studentID;        //Student ID
    string studentName;   //Name of the student

public:
    StudentArray();
    StudentArray(int,string);
    
    int getID();
    string getName();
    
    void setID(int);
    void setName(string);
};
    
