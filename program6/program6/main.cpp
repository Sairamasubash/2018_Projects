/**********************************************************************************************************
 CSCI 240         Program 6     Fall 2018
 
 Programmer: Subash Muppalaneni(Z1844762), Udiyanshu Goyal(Z1851835)
 
 Section: CSCI 240-2
 
 TA: Sravya
 
 Date Due: 10/26/18
 
 Purpose: The purpose of this program is to decode each character in a encoded message file of quotes, by using the new fstream and cctype libraries. we also have to use six functions and two switch statements throughtout this program.
 **********************************************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cctype>

//Lines 15-19 are the five libraries used in this program.

using namespace std;

char changeUpperToLower(char);
char changeLowerToUpper(char);
char changePunctToDigit(char);
char changeDigitToPunct(char);
char changeSpecialToSpace(char);
bool isspecial(char);

//Lines 25-30 are the six finction prototypes.

/***************************************************************
 Function: main
 
 Use: This is where we test if the program file is opening correctly or if the program file is failing to open. We also use the while loop to decode each character in the program file. Finally In the main routine, we also call the six function that were written at the bottom of the program as part of the while loop (we also use this function to close the file.).
 
 Arguments:None
 
 Returns: 1. return 0: whenever we get the return value of 0 in the output, we can then confirm that our program was successful.
 
 Note: This in the main body of the entire program because this function is where everything runs through.
 ***************************************************************/

int main()    //The main routine.
{
    char myCharacter;
    int Alphabetic = 0, Digit = 0, Punctuation = 0, Whitespace = 0;
    
        ifstream inFile1; //Naming the file.
        inFile1.open( "encoded_quotes.txt" );  //Opening the givin file.
    
    if(inFile1.fail())
    {
        cout << "\t\t\t\t*****THE INPUT FILE DID NOT OPEN*****" << endl;
        exit(-1);
    }
        cout << "\t\t\t\t*****THE INPUT FILE OPENED*****" << endl;
    
    //In lines 41-46, we are testing is the input file failed to open or if it opened.
    
        inFile1 >> myCharacter; //Reading the characters from the file.
    
    while(inFile1)   //While the characters are in the file.
    {
    if (isupper(myCharacter))
    {
        cout << changeUpperToLower(myCharacter);
        Alphabetic += 1;
    }
    else if (islower(myCharacter))
    {
        cout << changeLowerToUpper(myCharacter);
        Alphabetic+= 1;
    }
    else if (ispunct(myCharacter))
    {
        cout << changePunctToDigit(myCharacter);
        Punctuation += 1;
    }
    else if (isdigit(myCharacter))
    {
        cout << changeDigitToPunct(myCharacter);
        Digit += 1;
    }
    else if (isspecial(myCharacter))
    {
        cout << changeSpecialToSpace(myCharacter);
        Whitespace += 1;
    }
        inFile1 >> myCharacter;
    }
    
    //Start of extra credit number one.
    int TotalCharacters;
        TotalCharacters = Alphabetic + Digit + Punctuation + Whitespace;
    
    cout << "\n\n\nThis file contains a total of " << TotalCharacters << " characters" << endl;
    cout << "\n Alphabetic characters: " << Alphabetic << endl;
    cout << " Digit characters: " << Digit << endl;
    cout << " Punctuation Characters: " << Punctuation << endl;
    cout << " Whitespace characters: " << Whitespace << endl;
    
    //Start of extra credit number two.
    
    cout << "\nThese quotes are from the movie called: A Christmas Story" << endl;
    
    
    //In lines 54-74, we are calling the six finctions from below and we are using the special finctions that are contained in the cctype library.
    
        inFile1.close();    //Closeing the file.
        cout << endl << endl << endl;
    
    return 0;
}

/***************************************************************
 Function: changeUpperToLower
 
 Use: changes an uppercase letter into a lowercase letter, and then subtracts 1. It also changes the value of character 'A' into character 'z' by using an if statement.
 
 Arguments: 1. upperToLower: represents the uppercase letters that are going be decoded lowercase letters.
 
 Returns: 1. return 'z': returns the character 'z', whenever there is a character 'A' in the file.
          2. return changingToLower: returns the new decoded lowercase value of a perticular uppercase letter.
 
 Note: this funtion (changeUpperToLower) uses a special tolower function that is contained in the cctype library.
 ***************************************************************/

char changeUpperToLower(char upperToLower) //Start of the changeUpperToLower function.
{
    char changingToLower;
    
    changingToLower = tolower(upperToLower) - 1;  //Using tolower from the cctype library.
    
    if(upperToLower == 'A')
    {
        return 'z';
    }
    return changingToLower;
}

/***************************************************************
 Function: changeLowerToUpper
 
 Use: changes a lowercase letter into an uppercase letter, and then subtracts 1. It also changes the value of character 'z' into character 'A' by using an if statement.
 
 Arguments: 1. lowerToUpper: represents the lowercase letters that are going be decoded into uppercase letters.
 
 Returns: 1. return 'A': returns the character 'A', whenever there is a character 'z' in the file.
          2. return changingToUpper: returns the new decoded uppercase value of a perticular lowercase letter.
 
 Note: this funtion (changeLowerToUpper) uses a special toupper function that is contained in the cctype library.
 ***************************************************************/

char changeLowerToUpper(char lowerToUpper) //Start of the changeLowerToUpper finction.
{
    char changingToUpper;
    
    changingToUpper = toupper(lowerToUpper) + 1;  //Using toupper from the cctype library.
    
    if(lowerToUpper == 'z')
    {
        return 'A';
    }
    return changingToUpper;
}

/***************************************************************
 Function: changePunctToDigit
 
 Use: changes all the given punctuation characters into specific digit characters by using a switch statement.
 
 Arguments: 1. punctToDigit: represents the punctuation characters that are going to be decoded into digit characters
 
 Returns: 1. return newPunctValue: returns the new decoded digit character of a specific punctuation character.
 
 Note: in this function, we only need one return statement because we can just assign each digit character to a char variable and return that.
 ***************************************************************/

char changePunctToDigit(char punctToDigit) //Start of the changePunctToDigit function.
{
    char newDigitValue = 'a';
    
    switch (punctToDigit)
    {
    case ')':
        newDigitValue = '0';
        break;
    case '!':
        newDigitValue = '1';
        break;
    case '@':
        newDigitValue = '2';
        break;
    case '#':
        newDigitValue = '3';
        break;
    case '$':
        newDigitValue = '4';
        break;
    case '%':
        newDigitValue = '5';
        break;
    case '^':
        newDigitValue = '6';
        break;
    case '&':
        newDigitValue = '7';
        break;
    case '*':
        newDigitValue = '8';
        break;
    case '(':
        newDigitValue = '9';
        break;
    default:
        newDigitValue = punctToDigit;
        break;
    }
    
    //Lines 121-152 is the first switch statement.
    
    return newDigitValue;
}

/***************************************************************
 Function: changeDigitToPunct
 
 Use: changes all the given digit characters into specific punctuation characters by using a switch statement.
 
 Arguments: 1. digitToPunct: represents the digit characters that are going to be decoded into punctuation characters
 
 Returns: 1. return newDigitValue: returns the new decoded punctuation character of a specific digit character.
 
 Note: in this function, we only need one return statement because we can just assign each punctuation character to a char variable and return that.
 ***************************************************************/

char changeDigitToPunct(char digitToPunct)   //Start of the changeDigitToPunct function.
{
    char newPunctValue = 'a';
    
    switch (digitToPunct)
    {
    case '9':
        newPunctValue = ',';
        break;
    case '8':
        newPunctValue = '"';
        break;
    case '7':
        newPunctValue = '!';
        break;
    case '6':
        newPunctValue = ';';
        break;
    case '5':
        newPunctValue = '?';
        break;
    case '4':
        newPunctValue = '\'';
        break;
    case '3':
        newPunctValue = '(';
        break;
    case '2':
        newPunctValue = ')';
        break;
    case '1':
        newPunctValue = '.';
        break;
    case '0':
        newPunctValue = '-';
        break;
    default:
        newPunctValue = digitToPunct;
        break;
    }
    
    //Lines 166-197 is the second switch statement.
    
    return newPunctValue;
}

/***************************************************************
 Function: changeSpecialToSpace
 
 Use: whenever there is a special character of 20, this function changes it into a new line. Also, whenever there is a special character of 22, this function changes it into a space.
 
 Arguments: 1. specialToSpace: represents the special characters that are going to be decoded into a space or a new line.
 
 Returns: 1. return changingToSpaceOrNewLine: returns the new decoded space, or new line of a special character.
 
 Note: this function is like the previous two functions but it is much shorter and it uses an if statement instead of a switch statement.
 ***************************************************************/

char changeSpecialToSpace(char specialToSpaceOrNewLine)    //Start of the changeSpecialToSpace function.
{
    char changingToSpaceOrNewLine = 'a';
    
    if ((int)specialToSpaceOrNewLine == 20)
    {
        changingToSpaceOrNewLine = '\n';
    }
    else if ( (int)specialToSpaceOrNewLine == 22)
    {
        changingToSpaceOrNewLine = ' ';
    }
    return changingToSpaceOrNewLine;
}

/***************************************************************
 Function: isspecial
 
 Use: this function checks if the characters have integer values of 20 or 22 by using an if else statement.
 
 Arguments: 1. inChar: represents the two integer values (20 or 22) that will be checked.
 
 Returns: 1. return ture: returns true if a specific character has an integer value of 20 or 22.
          2. return false: returns false if a specific character does not have and integer value of 20 or 22.
 
 Note: this is a boolean character, so the only thing it can do is check is something is true or false.
 ***************************************************************/

bool isspecial(char inChar)    //Start of th boolean statement (True or False).
{
    
    if ((inChar==20) or (inChar==22))
    {
        return true;
    }
    else
        return false;
}


