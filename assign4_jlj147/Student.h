// File Name: Student.h
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
using namespace std;

class Student
{
private:
    int studentID;        //Student ID
    string studentName;   //Name of the student
    int studentAverage;   //Students avearge of test scores
    string studentAddress; //Students address
    int studentScores[10];
    int *scores;            //Pointer to students average test scores
    
public:
    Student();
    Student(int,string, double, string);
    
    void setID(int);
    void setName(string);
    void setAverage(double);
    void setAddress(string);
    
    int getID();
    string getName();
    double getAverage();
    string getAddress();
    void getScroes();
};
