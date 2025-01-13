/**********************************************************************************************************
 CSCI 240         Program 4     Fall 2018
 
 Programmer: Subash Muppalaneni
 
 Section: CSCI 240-2
 
 Date Due: 9/28/18
 
 Purpose: The Purpose of this program is to create a craps game using the random number generator and with symbolic constants.
 **********************************************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
int main()
{
   
    const int BIG_RED = 7;
    const int YO_LEVEN = 11;
    const int SNAKE_EYES = 2, CRAPS_THREE = 3, BOX_CARS = 12;
        
    int diceOne, diceTwo, diceValue, pointValue=0;
    char Continue = 'y';
    
    //Lines 21-26 is where all of the symbolic constants and variables (integers and characters) are located for future use.
    
        srand(22);
    
    //Line 30 is where the seed for the random number generator is located, having different number in the seed will give the user different random numbers.
        
            diceOne = ((rand() % 6) + 1);
            diceTwo = ((rand() % 6) + 1);
            diceValue = diceOne + diceTwo;
    
    // lines 34-36 are dice one and twos random number generators (1-6) for the first roll, and also the addition of dice one and twos random number, which becomes the dice value.
    
        cout << "\nPlayer rolled a: " << diceOne << " + " << diceTwo << " = " << diceValue << endl;     // Tells the player what he rolled for the first time.
        
        if (diceValue == BIG_RED or diceValue == YO_LEVEN) //First roll winning numbers.
        {
            cout << "You won! " << endl;     //Tells the user that he rolled a 7, or 11 and he won.
        }
        
        else if (diceValue == SNAKE_EYES or diceValue == CRAPS_THREE or diceValue == BOX_CARS)     //First roll losing numbers.
        {
            cout << " craps! You lost! " << endl;     //Tells the user that he rolled a 2, 3, or 12 and he lost.
        }
        
        else if (diceValue == 4 or diceValue == 5 or diceValue == 6 or diceValue == 8 or
                 diceValue == 9 or diceValue == 10)     //If one of these numbers are rolled on the first roll, it will be the next winning point.
        {
            cout << "\nYour point is " << diceValue << "\n" << endl;     //Tells the user what he needs to roll next to win.
            
        while (Continue == 'y')     //while loop for possible 2 or more rolls.
        {
            diceOne = ((rand() % 6) + 1);
            diceTwo = ((rand() % 6) + 1);
            pointValue = diceOne + diceTwo;
            
            // lines 57-59 are the same thing as lines 34-36, but they are programed for 2 or more rolls.
                
            cout << "Player rolled a: " << diceOne << " + " << diceTwo << " = " << pointValue << endl;     // Tells the player what he rolled.
                
            if (diceValue == pointValue)     // winning number (point value)
        {
            cout << "\nyou have rolled your point! and you have won!" << endl;     //Tells the player that he won.
            Continue = 'n';
        }
                
            else if (pointValue == 7)     //losing number (7)
        {
            cout << "\nYou have seven'd out! you lost!" << endl;     // Tells the player that he lost
            Continue = 'n';
        }
        }
        }
        
           return 0;
        }
