// File Name: Students.h
//
// Author: Jayce Jones
// Date: 11/18/16
// Assignment Number: 8
// CS 3358: Fall 2016
// Instructor: CJ Hwang
//
// Represents a zstudent record list in vector form
// Includes a students ID, name, GPA, and address
// Supports searching for student ID as a way to find the full
// student record
#include <string>
#include <vector>
using namespace std;

class Student
{
private:
    int studentID;          //Student ID
    string studentName;     //Name of the student
    double studentGPA;      //Students GPA
    string studentAddress; //Students address
    int scores[60];        //Stores 60 student scores, 3 per student
    int *scorePointer;     //Pointer to student scores
    
public:
    Student();
    Student(int,string,double,string,int[]);
    
    void setID(int);
    void setName(string);
    void setGPA(double);
    void setAddress(string);
    void setScores(int[]);
    
    int getID();
    string getName();
    double getGPA();
    string getAddress();
    int getScores();
    
    void print();
    void printVect(vector<Student>,int);
    void quickSort(vector<Student>&,int,int);
    int partition (vector<Student>&,int,int);
    
    int binarySearch(vector<Student>,int,int,int);
};
