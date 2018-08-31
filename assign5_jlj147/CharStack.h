// File Name: CharStack.h
//
// Author: Jayce Jones
// Date: 10/14/16
// Assignment Number: 5
// CS 3358: Fall 2016
// Instructor: CJ Hwang
//
//Converts infix expresions to postfix expressions

#include <string>
using namespace std;

class CharStack
{
private:
    char *stackk;   //The stack array
    int stackSize; //The array size
    int top;       //Index of the element at the top of the stack
    
public:
    //Constructor
    CharStack(int);
    ~CharStack();
    
    //Stack operations
    void push(char);
    char pop();
    bool isFull() const;
    bool isEmpty() const;
    void displayStack();
    char getTop();
    
    //Conversion
    bool isOperator(char);
    bool isOperand(char);
    int higherPrecedence(char,char);
    int getPrecedence(char);
    string newExpression(string);
};
