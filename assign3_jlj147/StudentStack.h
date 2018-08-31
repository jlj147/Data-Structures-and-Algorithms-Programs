// File Name: StudentStack.h
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
#include "StudentArray.h"
using namespace std;

class StudentStack
{
private:
    StudentArray *studentStack;     //The stack array
    int stackSize;                  //The stack array size
    int top;                        //Index to the top of the stack
    
public:
    //Constructor
    StudentStack(int);
    StudentStack(const StudentStack &);
    ~StudentStack();
    
    //Stack operations
    void push(StudentArray);
    StudentArray pop();
    bool isFull() const;
    bool isEmpty() const;
    void displayStack();
};



