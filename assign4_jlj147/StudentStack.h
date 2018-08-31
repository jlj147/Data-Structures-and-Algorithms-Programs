// File Name: StudentStack.h
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
#include "StudentList.h"
using namespace std;

class StudentStack
{
private:
    struct StudentNode
    {
        Student data;
        StudentNode* next;
    };
    StudentNode* top; // ptr to top
    
public:
    // Constructor
    StudentStack() { top = NULL; } // empty stack
    ~StudentStack();
    // Stack operations
    void push(Student);
    Student pop();
    bool isFull() const {return false;}
    bool isEmpty() const {return top == NULL;}
    void displayStack();
};
