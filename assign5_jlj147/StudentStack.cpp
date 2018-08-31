// File Name: StudentStack.cpp
//
// Author: Jayce Jones
// Date: 10/14/16
// Assignment Number: 5
// CS 3358: Fall 2016
// Instructor: CJ Hwang
//
//Converts infix expresions to postfix expressions

#include <iostream>
#include <cassert>
#include <string>
#include <iomanip>

#include "CharStack.h"

using namespace std;

//***********************************************************
// CharStack: Creates an empty stack array
//***********************************************************
CharStack::CharStack(int size)
{
    if(size <= 0)
    {
        size = 1;
    }
    stackk = new char[size];
    stackSize = size;
    top = -1;
}

//*********************************************************
// ~StudentList: Destructor that deallocates the stack
//*********************************************************
CharStack::~CharStack()
{
    delete [] stackk;
}
//*******************************************************************
// push: Appends the passed in character to the back of the string
// ch: The passed in character to be appended (popped) into the stack
//*******************************************************************
void CharStack::push(char ch)
{
    assert(!isFull());
    top = top+1;
    stackk[top] = ch;
}

//*******************************************************************
// pop: Pops off whatever is at the top of the stack
//
// returns: What was popped
//*******************************************************************
char CharStack::pop()
{
    assert(!isEmpty());
    
    return stackk[top--];
}

//**********************************************************************
// isFull: Checks if the string is full
//
//returns: Always returns false because the expression is never too long
//**********************************************************************
bool CharStack::isFull() const
{
    return false;
}

//**********************************************************************
// isEmpty: Checks if the string is empty
//
//returns: Returns true if the stack is empty, false otherwise
//**********************************************************************
bool CharStack::isEmpty() const
{
    if (top == -1)
    {
        return true;
    }
    return false;
}

//**********************************************************************
// getTop: Gets element on top of stack
//
//returns: Element that is on the top of the stack
//**********************************************************************
char CharStack::getTop()
{
    return stackk[top];
}

//**********************************************************************
// setPrecedence: Sets the precednece that an operator has in expressions
// anOperator: An operator that is to have its precedence set
//
//returns: Value specifying precednece, the higher the value returned
//         the higher the precedence
//**********************************************************************
int setPrecedence(char anOperator)
{
    switch (anOperator)
    {
        case '/':
        case '*':
        case '%':
            return 2;
            
        case '+':
        case '-':
            return 1;
            
        default :
            return 0;
    }
}

//**********************************************************************
// isOperator: Verifies that a character is an operator
// ch: A charcter from the infix expression
//
//returns: Returns true if the character is an operator, false otherwise
//**********************************************************************
bool isOperator(char ch)
{
    if (ch == '*' || ch == '/' || ch == '%' || ch == '+' || ch == '-')
        return true;
    else
        return false;
}

//**********************************************************************
// getTop: Verifies that a character is an operand
// ch: A character from the infix expression
//
//returns: Returns true if the characther is an operand, false otherwise
//**********************************************************************
bool isOperand(char ch)
{
    if(!isOperator(ch) && ch != ')' && ch != '(')
        return true;
    else
        return false;
}

//**********************************************************************
// higherPrecendence: Function that takes opearators from the infix
//                    expression and compares them
// operator 1: An operator to be comapred
// operator 2: An operator to be compared
//
//returns: Returns the operators in order of higher precednce
//**********************************************************************
int higherPrecedence(char operator1, char operator2)
{
    int op1precedence = setPrecedence(operator1);
    int op2precedence = setPrecedence(operator2);
    
    if (op1precedence == op2precedence)
    {
        return true;
    }
    if (op1precedence > op2precedence)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//**********************************************************************
// newExpression: Converts an expression from infix to postfix
// expression: The infix expression entered by the user
//
//returns: Returns the postfix expression
//**********************************************************************
string newExpression(string expression)
{
    int length = (uint32_t)expression.length();
    CharStack expressionStack(length);
    string postfix = "";
    
    //Reading in expression
    for(int i = 0; i < length; i++)
    {
        //If an operator is encountered and there is already another
        //operator in the stack then take them out of the stack and
        //assign their precedence, then append them to the postfix
        //expression
        if (isOperator(expression[i]))
        {
            while (!expressionStack.isEmpty() && expressionStack.getTop()
                   != '(' && higherPrecedence(expressionStack.getTop(),
                   expression[i]))
            {
                postfix += expressionStack.getTop();
                expressionStack.pop();
            }
            expressionStack.push(expression[i]);
        }
        
        //Append the operand to the postfix
        else if (isOperand(expression[i]))
        {
            postfix += expression[i];
            
        }
        
        //Push any opening parentheses
        else if (expression[i] == '(')        {
            expressionStack.push(expression[i]);
        }
        
        //If there is a closing parenthesis pop off all of the elements and
        //add to postifx expression until an opening parenthese is popped
        else if(expression[i] == ')')
        {
            while (!expressionStack.isEmpty()
                   && expressionStack.getTop() != '(')
            {
                postfix += expressionStack.getTop();
                expressionStack.pop();
            }
            expressionStack.pop();
        }
    }
    
    //Pop off any thing remaining in the stack
    while (!expressionStack.isEmpty())
    {
        postfix += expressionStack.getTop();
        expressionStack.pop();
    }
    
    //Return the postfix expression
    return postfix;
}
