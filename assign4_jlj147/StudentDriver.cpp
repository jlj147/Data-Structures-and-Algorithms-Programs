// File Name: StudentDriver.cpp
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
#include <string>
#include <iomanip>
#include <ctime>

#include "StudentStack.h"

using namespace std;
int main()
{
    Student records[15]; //Creating student records array
    Student popped[5];
    StudentStack stack;  //For accessing memeber function
    
    srand(unsigned(time(NULL)));
    
    //Assigning students ID's
    for (int i=0; i<15; i++)
    {
        int randomNumber;
        randomNumber = rand()% 1000000+1;
        records[i].setID(randomNumber);
    }
    
    //Assigning student names and locations
    records[0].setName("Arya");
    records[0].setAddress("Braavos");
    
    records[1].setName("Podrick");
    records[1].setAddress("Silverhill");
    
    records[2].setName("Eddard");
    records[2].setAddress("Winterfell");
    
    records[3].setName("Jorah");
    records[3].setAddress("Volantis");
    
    records[4].setName("Dany");
    records[4].setAddress("Mereen");
    
    records[5].setName("Theon");
    records[5].setAddress("Pyke");
    
    records[6].setName("Davos");
    records[6].setAddress("White Harbor");
    
    records[7].setName("Tyrion");
    records[7].setAddress("Pentos");
    
    records[8].setName("Myrcella");
    records[8].setAddress("Sunspear");
    
    records[9].setName("Cersi");
    records[9].setAddress("Kings Landing");
    
    records[10].setName("Brienne");
    records[10].setAddress("Tarth");
    
    records[11].setName("Jamie");
    records[11].setAddress("Lannisport");
    
    records[12].setName("Catelyn");
    records[12].setAddress("Riverrun");
    
    records[13].setName("Samwell");
    records[13].setAddress("Horn Hill");
    
    records[14].setName("Margaery");
    records[14].setAddress("Highgarden");
    
    cout << "Unsorted array: " << endl;
    cout << "ID     " << "Name     " << "Average  "
    << "Address     " << endl;
    for (int i=0; i<15; i++)
    {
        cout << left << setprecision(1) << fixed << setw(7)
        << records[i].getID() << setw(9) << records[i].getName()
        << setw(9) << records[i].getAverage()<< records[i].getAddress()
        << endl;
    }
    cout << endl;

    
    //Transfering array to linked list
    StudentList listings;   //To hold student listings
    for (int i=0; i<15; i++)
    {
        listings.appendStudent(records[i]);
    }
    
    //Pushing linked list to dynamic stack
    Student info;
    for(int k=0; k<15; k++)
    {
        info = records[k];
        stack.push(info);
    }
    
    //Display Linked List
    listings.displayRecords();
    cout << endl;
    
    cout << "Popped Records: " << endl;
    cout << "ID     " << "Name     " << "Average  "
    << "Address     " << endl;
    for (int i=0; i<5; i++)
    {
        popped[i] = stack.pop();
        cout << left << setprecision(1) << fixed << setw(7)
             << popped[i].getID() << setw(9)
             << popped[i].getName() << setw(9)
             << popped[i].getAverage() << popped[i].getAddress() << endl;
    }
    cout << endl;
    
    //Push each entry of linked list onto stack
    stack.displayStack();
    cout << endl;
    
    return 0;
}
