// File Name: StudentList.cpp
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
// insertStudent: Adds a new student to the records, organizes the
//                student records by student ID
// newStudent: Holds the ID, name, GPA, and location of the student
//             to be added to the student records
//*******************************************************************
void StudentList::insertStudent(Student newStudent)
{
    StudentNode *newNode; //Pointer created for error check
    StudentNode *nodeptr; //Pointer created to point to the student being
                         //passed in
    StudentNode *previousNode = nullptr; 
    
    //Allocate a new node and store student there
    newNode = new StudentNode;
    newNode -> data = newStudent;

    //If there are no nodes in the list make
    //newNode the first node
    if (!head)
    {
        head = newNode;
        newNode -> next = nullptr;
    }

    else //Otherwise, insert newNode
    {
        //Position nodeptr at the head of the list
         nodeptr= head;
        
        //Initialize previousNode to nullptr
        previousNode = nullptr;
        
        //Skip all nodes whose value is less than the newStudents ID
        while (nodeptr != nullptr && nodeptr->data.getID() < newStudent.getID())
        {
            previousNode = nodeptr;
            nodeptr = nodeptr -> next;
        }

        //If the new node is to be the first in the list
        //insert it before all other nodes
        if(previousNode == nullptr)
        {
            head = newNode;
            newNode -> next = nodeptr;
        }
    
        else //Otherwise insert after the previous node
        {
            previousNode -> next = newNode;
            newNode -> next = nodeptr;
        }
    }
}

//***************************************************************************
// removeStudent: Takes a students ID, if the Students ID is found in the
//                records, removes the record of the student
//
// studentID:The ID of the student whose record is to be removed
//
// returns true if the student record is successfully removed, and false
// if it is not
//***************************************************************************
bool StudentList::removeStudent(int studentID)
{
    StudentNode *p = head; //Create pointer to traverse the list and
                           //set it equal to the head pointer
    StudentNode *n = nullptr; //Pointer to traverse the list
    
    //skip nodes that are not equal to ID
    while (p != NULL && (p->data.getID() != studentID))
    {
        n = p;
        p = p -> next;
    }
    
    //If the list is empty of the student is not in the student records
    if (p==NULL)
    {
        return false;
    }
    
    //if p is not null: the student ID was found
    if (p != NULL)
    {
        if (p==head) //p points to the first element
        {
            head = p ->next;
            delete p;
        }
        else
        {
            n->next = p->next;
            delete p;
        }
    }
    return true;
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
    cout << "ID     " << "Name     " << "GPA   " << "Address     " << endl;
    
    while (p) //While p is pointing to a node display student list
    {
        cout << left << setw(7) << p->data.getID() << setw(9)
        << p->data.getName() << setw(6) << p->data.getGPA()
        << setw(4) << p->data.getAddress();
        
        p = p->next;
        cout << endl;
    }
}

