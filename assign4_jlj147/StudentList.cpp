// File Name: StudentList.cpp
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
#include <cstddef>
#include <iomanip>
#include "StudentList.h"

using namespace std;

//***********************************************************
// StudentList: Constructor that creats an empty list
//***********************************************************
StudentList::StudentList()
{
    head = NULL;  //Sets head pointer equal to NULL
}

//*********************************************************************
// ~StudentList: Destructor that deallocates all the node in the list
//*********************************************************************
StudentList::~StudentList()
{
    StudentNode *p = head; //Create pointer and
    //set it equal to the head pointer
    StudentNode *n;       //Pointer to traverse the list
    while (p != NULL)
    {
        n = p -> next;  //Saves address of next node
        delete p;
        p = n;          //Point p to next node
    }
}

//*******************************************************************
// appendStudent: Adds a new student to the student list
//
// newStudent: Holds a students ID, name, GPA, and location to be added
//             to the student list
//*******************************************************************
void StudentList::appendStudent(Student newStudent)
{
    StudentNode *newNode;     //Pointer created for error check
    newNode = head;           //Pointer set equal to head pointer
    StudentNode *nodeptr;   //Pointer created to point to the student being
    //passed in
    
    //Allocating the new node
    nodeptr = new StudentNode;
    nodeptr -> data = newStudent;
    nodeptr -> next = NULL;
    
    
    //If head pointer is NULL, create a node between them
    if (head==NULL)
    {
        head = nodeptr;
    }
    
    //Else add the node to the list
    else
    {
        StudentNode *p = head;
        
        while(p->next != NULL)
        {
            p = p -> next;
        }
        p -> next = nodeptr;
    }
}

//*******************************************************************
// displayRecords: Displays the information for each student that has been
//                 added to the student list, one student per line
//*******************************************************************
void StudentList::displayRecords()
{
    StudentNode *p;  //Pointer to traverse the list
    p = head;       //Set pointer equal to head pointer
    
    cout << "Linked List:" << endl;
    cout << "ID     " << "Name     " << "Average  "
         << "Address     " << endl;
    
    while (p) //While p is pointing to a node display student list
    {
        cout << left << setprecision(1) << fixed <<
        setw(7) << p->data.getID() << setw(9) << p->data.getName()
        << setw(9) << p->data.getAverage() << p->data.getAddress();
        
        p = p->next;
        cout << endl;
    }
}
