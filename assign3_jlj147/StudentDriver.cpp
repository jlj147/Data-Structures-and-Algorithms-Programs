// File Name: StudentDriver.cpp
//
// Author: Jayce Jones
// Date: 09/23/16
// Assignment Number: 2
// CS 3358: Fall 2016
// Instructor: CJ Hwang
//
// Represents a student record list
// Includes a students ID, name, avearge test score, and address
// Takes the student list and creates a stack, pops from stack
// and displays the list as if it is a stack

#include <iostream>
#include <string>
#include <iomanip>

#include "StudentStack.h"

using namespace std;

int main()
{
    StudentArray records[15]; //Creating student records array
    StudentArray killed[5];   //Creating array of student popped off stack
    StudentStack stack(15);
    
    double testScore; //A students single test score
    double totalScore; //The total of all 10 student test scores
    const int TESTS = 10;
    double average;
    
    srand(unsigned(time(NULL)));
    
    //Assigning students ID's
    for (int i=0; i<15; i++)
    {
        int randomNumber;
        randomNumber = rand()% 1000000+1;
        records[i].setID(randomNumber);
    }
    
    //Genretaing 10 test scores for each student
    //and calcuting the average of those scores
    for (int i=0; i<15; i++)
    {
        totalScore = 0; //Reseting running total to zero
        
        for (int i=0; i<10; i++)
        {
            testScore = rand() % 100+1;
            totalScore += testScore; //Keeping running total
        }
        average = totalScore/TESTS;
        records[i].setAverage(average);
        records[i].setPointer(average);
    }
    
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
    
    //Displaying student records in the array
    cout << "Student Array: " << endl;
    cout << "ID     " << "Name     " << "Average  " << "Address     " << endl;
    for (int i=0; i<15; i++)
    {
        cout << left << setprecision(1) << fixed << setw(7)
        << records[i].getID() << setw(9) << records[i].getName()
        << setw(9) << records[i].getAverage() << records[i].getAddress()
        << endl;
    }
    cout << endl;
    
    //Pushing all students from the array to a static stack
    for (int i=0; i<15; i++)
    {
        stack.push(records[i]);
    }
    
    //Popping 5 student records
    for (int i=0; i<5; i++)
    {
        killed[i]=stack.pop();
    }
    
    //Display the student records that were popped
    cout << "Popped Records: " << endl;
    cout << "ID     " << "Name     " << "Average  " << "Address     " << endl;
    for (int i=0; i<5; i++)
    {
        cout << left << setprecision(1) << fixed << setw(7)
        << killed[i].getID() << setw(9) << killed[i].getName()
        << setw(9) << killed[i].getAverage() << killed[i].getAddress()
        << endl;
    }
    cout << endl;
    

    //Displaying the remaining student records in the stack
    stack.displayStack();

    return 0;
}
