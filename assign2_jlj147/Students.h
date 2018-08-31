// File Name: Students.h
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

#include <string>
using namespace std;

class Student
{
private:
    int studentID;        //Student ID
    string studentName;   //Name of the student
    double studentGPA;    //Students GPA
    string studentAddress; //Students address
    
public:
    Student();
    Student(int,string,double,string);
    
    int getID();
    string getName();
    double getGPA();
    string getAddress();
    
    void setID(int);
    void setName(string);
    void setGPA(double);
    void setAddress(string);
};
