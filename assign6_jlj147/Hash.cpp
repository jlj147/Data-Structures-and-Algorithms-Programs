// File Name: Hash.cpp
//
// Author: Jayce Jones
// Date: 10/29/16
// Assignment Number: 6B
// CS 3358: Fall 2016
// Instructor: CJ Hwang
//
// Represents a student record list hash table
// Includes a students ID and name
// Supports searching through list for a students name
#include <iostream>
#include <string>
#include <iomanip>
#include "Hash.h"

using namespace std;

//***********************************************************
// Hash: Constructs a hash table with default values
//***********************************************************
Hash::Hash()
{
    for (int i=0; i<113; i++)
    {
        table[i]=-1;
    }
}

//*******************************************************************
// create: Generates hash key
// ID: Student ID to place in hash table
//
// returns: The hash key
//*******************************************************************
int Hash::create(int ID)
{
    int key = ID%113;
    return key;
}

//*******************************************************************
// linear_probe: Handles collisions when inserting info into the hash
//               table
// Key: A key corresponding to student ID
// ID: The student ID
//*******************************************************************
void Hash::linear_probe(int key,int ID)
{
    int flag=0;
    int count=0;
    int i=0;
    
    if (table[key]==-1) //If hash location is empty place ID in hash table
    {
        table[key]=ID;
    }
    else
    {
        while (i<113)
        {
            if (table[i] != -1)
            {
                count++;
            }
            i++;
        }
        
        if(count==113) //Check if hash is full
        {
            cout << "The hash table is full: " << endl;
            exit(1);
        }
        
        for (i=key+1;i<113;i++) //Linear search starting from key location
        {
            if(table[i]==-1) //Look for a location that is empty
            {
                table[i]=ID; //Put ID at location
                flag=1;
                break;
            }
        }
        
        for(i=0;i<key&&flag==0;i++) //Linear search from start location to
                                    //key location if no location was found
        {
            if (table[i]==-1)   //Look for location that is empty
            {
                table[i]=ID; //Put ID at location
                flag=1;
                break;
            }
        }
    }
}

//*******************************************************************
// display: Display the hash table
//*******************************************************************
void Hash::display()
{
    cout << "Hash Table: Linear Probing " << endl;
    cout << endl;
    
    cout << "Location ID" << endl;
    
    for(int i=0;i<113;i++)
    {
        if (table[i] != -1)
        {
            cout << fixed << left << setw(8) << i << " " << table[i];
            cout << endl;
        }
    }
    cout << endl;
}

//*******************************************************************
// search: Searches for a students ID at a key
// key: The key of the student ID that is to be searched for
//
// returns: A key that corresponds to the location of a students ID
//*******************************************************************
int Hash::search(int key)
{
    int hash = HashFunc(key);
    int temp = table[hash];
    
    if (temp != -1)
    {
        cout << "The Student ID at key value " << key << " is " << temp;
        cout << endl;
        return temp;
    }
    else
    {
        cout << "There is no student ID at key value " << key << endl;
        return -1;
    }
}

//*******************************************************************
// Key: HashFunc
// ID: Student key for which a key is created
//
// returns: A key for the student ID
//*******************************************************************
int Hash::HashFunc(int key)
{
    return key%113;
}


