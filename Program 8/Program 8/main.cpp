/****************************************************************************************************
 CSCI 240         Program 8     Fall 2018
 
 Programmer: Subash Muppalaneni(Z1844762)
 
 Section: CSCI 240-2
 
 TA: Murtuza
 
 Date Due: 11/20/18
 
 Purpose: The purpose of this program is to recreate the craps program. But in this program we are using (object oriented programing) classes, menthods, and constructors. For this program, we are also adding a loop for the user to play the game as many times as they want.
 
 ****************************************************************************************************/

//Below are all of my libraries.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;


class Die                 //This is my class and inside is where all of the objects are located.
{
public:                 //Here are all of the public variables.
    
    Die()             //Default constructor.
    {
        roll();      //roll method is being called.
    }
    
    /***************************************************************
     Function/Method: roll
     
     Use: In this method, we are creating the queation needed for the compiler to chose a random number between 1 and 6. Then we are making that random value equal to face (so we can call face later on in the program).
     
     Arguments: None
     
     Returns: No returns because the function header has void.
     
     Note: This is the first (out of two) methods needed for program 8.
     ***************************************************************/
    
    void roll()                     //Method number 1.
    {
        face = ((rand() % 6) + 1);   //Random number equation.
    }
    
    /***************************************************************
     Function/Method: getValue
     
     Use: This method is simply returning the face value (which is the random number value). So whenever we call this method/function later on in the program, it will just show the us the value or the random dice roll value.
     
     Arguments: None
     
     Returns: 1. return face: it returns the value of the dice roll number.
     
     Note: This is the second (out of two) methods needed for program 8.
     ***************************************************************/
    
    int getValue()                 //Method number 2.
    {
        return face;
    }
    
private:                               //Here are all of the private variables.
    int face;
    static const int NUM_SIDES;
    
};

const int Die::NUM_SIDES = 6; //We can use this integer anywhere in the program.

/***************************************************************
 Function: main
 
 Use: This is where we test if the program file is opening correctly or if the program file is failing to open. We also use the do while loop to let the use play the game again. Finally In the main routine, we are coding the parts where we tell the user if he won the craps game or if he lost the craps game.
 
 Arguments:None
 
 Returns: 1. return 0: whenever we get the return value of 0 in the output, we can then confirm that our program was successful.
 
 Note: This in the main body of the entire program because this function is where everything runs through.
 ***************************************************************/

int main()   //Main routine
{
    srand(35); //This is the seed for this program.
    
    const int BIG_RED = 7;
    const int YO_LEVEN = 11;
    const int SNAKE_EYES = 2, CRAPS_THREE = 3, BOX_CARS = 12;
    
    int diceOne, diceTwo, diceValue, pointValue;
    char Continue, myCh1 ;
    
     //Lines 93-98 is where all of the symbolic constants and variables (integers and characters) are located for future use.
    
        Die die1,die2;  //Using/calling the die constructor.
    
    do                    //Start of the do while loop.
    {
        pointValue = 0;
        
        die1.roll();
        die2.roll();
        
        diceOne = die1.getValue();
        diceTwo = die2.getValue();
        diceValue = diceOne + diceTwo;
        
        //Line 108-113 is where we are rolling the die, setting the die equeal to a integer variable, and adding the die for the first time.
        
        cout << "\nPlayer rolled a: " << diceOne << " + " << diceTwo << " = " << diceValue << endl;   // Tells the player what he rolled for the first time.
        
    if (diceValue == BIG_RED or diceValue == YO_LEVEN)  //First roll winning numbers.
    {
        cout << "You won! " << endl;    //Tells the user that he rolled a 7, or 11 and he won.
    }
    else if (diceValue == SNAKE_EYES or diceValue == CRAPS_THREE or diceValue == BOX_CARS)  //First roll losing numbers.
    {
        cout << " craps! You lost! " << endl;   //Tells the user that he rolled a 2, 3, or 12 and he lost.
    }
    else if (diceValue == 4 or diceValue == 5 or diceValue == 6 or diceValue == 8 or diceValue == 9 or diceValue == 10)   //If one of these numbers are rolled on the first roll, it will be the next winning point.
    {
        cout << "\nYour point is " << diceValue << "\n" << endl;   //Tells the user what he needs to roll next to win.
        
        Continue = 'y';
            
    while (Continue == 'y')   //while loop for possible 2 or more rolls.
    {
        die1.roll();
        die2.roll();
                
        diceOne = die1.getValue();
        diceTwo = die2.getValue();
        pointValue = diceOne + diceTwo;
        
        //Line 135-140 is where we are rolling the die, setting the die equeal to a integer variable, and adding the die for the second time.
                
        cout << "Player rolled a: " << diceOne << " + " << diceTwo << " = " << pointValue << endl;    // Tells the player what he rolled.
                
    if (diceValue == pointValue)   // winning number (point value)
    {
        cout << "\nyou have rolled your point! and you have won!" << endl;     //Tells the player that he won.
        Continue = 'n';
    }
    else if (pointValue == 7)     //losing number (7)
    {
        cout << "\nYou have seven'd out! you lost!" << endl;       // Tells the player that he lost
        Continue = 'n';
    }
    }
    }
        cout << "\nWould you like to play again (y or Y for yes)? " << endl;    //Asking the use if he wants to play again.
        cin >> myCh1;
    }
    while (myCh1 == 'y' or myCh1 == 'Y');           //End of the do while loop.
    
        cout << "\nThank you for playing, comeback and play anytime." << endl;
    
        return 0;
}



