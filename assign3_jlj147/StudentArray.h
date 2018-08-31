// File Name: StudentArray.h
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
using namespace std;

class StudentArray
{
private:
    int studentID;        //Student ID
    string studentName;   //Name of the student
    double studentAverage; //Students avearge of test scores
    string studentAddress; //Students address
    int *studentPointer;   //Pointer to students average test scores
    
public:
    StudentArray();
    StudentArray(int,string,double,string,int);
    
    void setID(int);
    void setName(string);
    void setAverage(double);
    void setAddress(string);
    void setPointer(int);
    
    int getID();
    string getName();
    double getAverage();
    string getAddress();
    int getPointer();
};
