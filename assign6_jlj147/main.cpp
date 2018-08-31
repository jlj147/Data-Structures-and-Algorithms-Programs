// File Name: main.cpp
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

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>

#include "Hash.h"

using namespace std;

int main()
{
    StudentArray records[30]; //Creating student records array
    srand(unsigned(time(NULL)));
    
    for (int i=0; i<30; i++)
    {
        int randomNumber;
        randomNumber = rand()% 999999+1;
        while (randomNumber < 100000)
        {
            randomNumber = rand()% 999999+1;
        }
        records[i].setID(randomNumber);
    }
    
    records[0].setName("Arya");
    records[1].setName("Podrick");
    records[2].setName("Eddard");
    records[3].setName("Jorah");
    records[4].setName("Dany");
    records[5].setName("Theon");
    records[6].setName("Davos");
    records[7].setName("Tyrion");
    records[8].setName("Myrcella");
    records[9].setName("Cersi");
    records[10].setName("Brienne");
    records[11].setName("Jamie");
    records[12].setName("Catelyn");
    records[13].setName("Samwell");
    records[14].setName("Margaery");
    records[15].setName("Hizdahr");
    records[16].setName("Stannis");
    records[17].setName("Jeor");
    records[18].setName("Tywin");
    records[19].setName("Brandon");
    records[20].setName("Bronn");
    records[21].setName("Osha");
    records[22].setName("Bran");
    records[23].setName("Illyrio");
    records[24].setName("Asha");
    records[25].setName("Tormund");
    records[26].setName("Varys");
    records[27].setName("Petyr");
    records[28].setName("Renly");
    records[29].setName("Roose");
    
    Hash h; //To create hash values
    int key; //Key value from user used to search hash table
    int found; //Retruned from search function
    
    for (int i=0; i<30; i++)
    {
        key = h.create(records[i].getID());
        h.linear_probe(key,records[i].getID());
    }
    
    h.display();
    
    do
    {
        cout << "Enter a key to find a students ID: ";
        cin >> key;
        found = h.search(key);
        
    }while (found != -1);
}
