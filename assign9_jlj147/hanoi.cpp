// File Name: StudentDriver.cpp
//
// Author: Jayce Jones
// Date: 11/25/16
// Assignment Number: 9
// CS 3358: Fall 2016
// Instructor: CJ Hwang
//
//This porgram displays solutions to the Towers of Hanoi games with the
// number of discs inputted by the user
#include <iostream>
using namespace std;

//Function prototype
void moveDiscs(int,char,char,char);

int main()
{
    int numDiscs;
    char again;
    char A_PEG = 'A';
    char B_PEG = 'B';
    char C_PEG = 'C';
    do
    {
        cout << "Enter the number of disks to play: ";
        cin >> numDiscs;
        //call to function to move discs
        moveDiscs(numDiscs, A_PEG, C_PEG, B_PEG);
        cout << "All the pegs are moved" << endl;
        cout << endl;
        cout << "To play again enter 'Y' to quit enter 'N'" << endl;
        cout << "Play Again?: ";
        cin >> again;
        cout << endl;
    }
    while(again == 'Y' || again == 'y');
    return 0;
}

//*******************************************************************
// moveDiscs: Displays a disc moves in the Towers of Hanoi game
// num: The number of disks to move
// fromPeg: The peg to move from
// toPeg: The peg to move to
// tempPeg: The temporary peg
//*******************************************************************
void moveDiscs (int num, char pegA, char pegC, char pegB)
{
    if (num > 0)
    {
        moveDiscs(num - 1, pegA, pegB, pegC);
        cout << "Move disk " << num << " from peg " << pegA
             << " to peg " << pegC << endl;
        moveDiscs(num-1, pegB, pegC, pegA);
    }
}
