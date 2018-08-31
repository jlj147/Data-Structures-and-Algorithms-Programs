// File Name: CharDriver.cpp
//
// Author: Jayce Jones
// Date: 10/14/16
// Assignment Number: 5
// CS 3358: Fall 2016
// Instructor: CJ Hwang
//
//Converts infix expresions to postfix expressions

#include <iostream>
#include <string>
#include "CharStack.h"
using namespace std;

string newExpression(string expression);

int main()
{
    string expression; //Infix expression entered by the user
    string postfix;    //Postfix expression returned from functions
    
    for (int i=0; i<10; i++)
    {
    cout<<"Enter an infix expression: ";
    getline(cin,expression);
    postfix = newExpression(expression);
    cout << "Postfix expression is: " << postfix << endl;
    }
    return 0;
}
