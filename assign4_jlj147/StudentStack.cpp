// File Name: StudentStack.cpp
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

#include <iostream>
#include <cassert>
#include <string>
#include <iomanip>

#include "StudentStack.h"

using namespace std;

StudentStack::~StudentStack(){
    StudentNode *p;
    StudentNode *n;
    
    // Position nodePtr at the top of the stack.
    p = top;
    
    // Traverse the list deleting each node.
    while (p != 0){
        n = p->next;
        delete p;
        p = n;
    }
}

//*******************************************************************
// push: Appends the passed in student to the top of the list
// newStudent: The passed in student to be appended(pushed) onto
//             the stack
//*******************************************************************
void StudentStack::push(Student newStudent)
{
    assert(!isFull()); //stack overflow
    
    StudentNode *temp; //Pointer to a new node
    
    //Allocate a new node
    temp = new StudentNode;
    temp->data = newStudent;
    
    if(isEmpty())
    {
        top=temp;
        temp->next=0;
    }
    else
    {
        temp->next=top;
        top = temp;
    }
}

//*******************************************************************
// pop: Pops off the student that is at the top of the list
//
// returns: The student that was popped
//*******************************************************************
Student StudentStack::pop()
{
    assert(!isEmpty());
    
    StudentNode *temp;
    Student data;
    
    data = top->data; //Retrieve front item
    temp = top->next;
    delete top;       //Deallocate front item
    top=temp;
    return data;
}

//*****************************************************
// displayStack: Displays the student list as a stack
//*****************************************************
void StudentStack::displayStack()
{
    StudentNode *temp=top;
    
    cout << "Student Stack: " << endl;
    cout << "ID     " << "Name     " << "Average  "
    << "Address     " << endl;
    
    while(temp!=NULL)
    {
        cout << left << setprecision(1) << fixed << setw(7)
        << temp->data.getID() << setw(9) << temp->data.getName()
        << setw(9) << temp->data.getAverage() << temp->data.getAddress()
        << endl;
        
        temp = temp->next;
    }
}


