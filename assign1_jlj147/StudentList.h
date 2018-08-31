// File Name: Student.h
//
// Author: Jayce Jones
// Date: 09/17/16
// Assignment Number: 1
// CS 3358: Fall 2016
// Instructor: CJ Hwang
//
// Represents a student record list
// Includes a students ID, name, GPA, and address
// Supports adding and displaying student records to an array and
// a list, both unsorted

#include "Students.h"

class StudentList
{
private:
    struct StudentNode
    {
        Student data;
        StudentNode *next;
    };
    
    StudentNode *head;
    
public:
    StudentList();
    ~StudentList();
    void appendStudent(Student);
    void displayRecords();
};
