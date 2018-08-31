// File Name: StudentStack.cpp
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

#include <iostream>
#include <cassert>
#include <string>
#include <iomanip>

#include "StudentStack.h"

using namespace std;

//***********************************************************
// StudentList: Constructor that creats an empty stack
//***********************************************************
StudentStack::StudentStack(int size)
{
    studentStack = new StudentArray[size];
    stackSize = size;
    top = -1;
}

//*********************************************************
// ~StudentList: Destructor that deallocates the stack
//*********************************************************
StudentStack::~StudentStack()
{
    delete [] studentStack;
}

//*******************************************************************
// push: Appends the passed in student to the top of the list
// newStudent: The passed in student to be appended(pushed) onto
//             the stack
//*******************************************************************
void StudentStack::push(StudentArray newStudent)
{
    assert(!isFull()); //stack overflow
    top++;
    studentStack[top] = newStudent;
}

//*******************************************************************
// pop: Pops off the student that is at the top of the list
//
// returns: The student that was popped
//*******************************************************************
StudentArray StudentStack::pop()
{
    assert(!isEmpty());
    return studentStack[top--];
}

//**********************************************************************
// isFull: Checks if the string is full
//
//returns: Always returns false because the string (stack) is never full
//**********************************************************************
bool StudentStack::isFull() const
{
    bool status;
        
    if (top == stackSize)
    {
        status = true;
    }
    else
        status = false;
    
        return status;
}

//**********************************************************************
// isEmpty: Checks if the string is empty
//
//returns: Returns true if the stack is empty, false otherwise
//**********************************************************************
bool StudentStack::isEmpty() const
{
    bool status;
    
    if(top==-1)
    {
        status = true;
    }
    else
        status = false;
    
    return status;
}

//*****************************************************
// displayStack: Displays the student list as a stack
//*****************************************************
void StudentStack::displayStack()
{
    cout << "Student Stack: " << endl;
    cout << "ID     " << "Name     " << "Average  " << "Address     " << endl;
    for (int i=0; i<10; i++)
    {
        cout << left << setprecision(1) << fixed << setw(7)
        << studentStack[top].getID() << setw(9) << studentStack[top].getName()
        << setw(9) << studentStack[top].getAverage()
        << studentStack[top].getAddress() << endl;
        top--;
    }
}


