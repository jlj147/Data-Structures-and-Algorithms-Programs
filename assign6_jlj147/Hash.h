// File Name: Hash.h
//
// Author: Jayce Jones
// Date: 10/29/16
// Assignment Number: 6A
// CS 3358: Fall 2016
// Instructor: CJ Hwang
//
// Represents a student record list hash table
// Includes a students ID and name
// Supports searching through list for a students name
#include <iostream>
#include "StudentArray.h"

class Hash
{
private:
    int table[113];
    
public:
    Hash();
    int create(int);
    void linear_probe(int,int);
    void display();
    int HashFunc(int);
    int search(int);
};
