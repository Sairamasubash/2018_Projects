/***************************************************************
 CSCI 240         Program 1     Fall 2018
 
 Programmer: Subash Muppalaneni
 
 Section: CSCI 240-2
 
 Date Due: 9/7/18
 
 Purpose: This program calculates the number of singles and total
 number of bases for a baseball player.
 ***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    
    int totalNumberOfHits, totalNumberOfDoubles, totalNumberOfTriples, totalNumberOfHomeRuns, totalNumberOfSingles, totalNumberOfBases;
    
    // Line 21 has all of the interger values (there can be no decimals) that I need for the program.
    
    cout << "Enter the number of hits: ";
    cin >> totalNumberOfHits;
    
    cout << "Enter the number of doubles: ";
    cin >> totalNumberOfDoubles;
    
    cout << "Enter the number of triples: ";
    cin >> totalNumberOfTriples;
    
    cout << "Enter the number of home runs: ";
    cin >> totalNumberOfHomeRuns;
    
    // Lines 25-35 are all asking the user to enter an integer, so lines could take the integers and convert them into the integer values from line 20.
    
   totalNumberOfSingles = totalNumberOfHits - totalNumberOfDoubles - totalNumberOfTriples - totalNumberOfHomeRuns;
    
    cout << "Number Of Singles:" << totalNumberOfSingles << endl;
    cout << "Number Of doubles: " << totalNumberOfDoubles << endl;
    cout << "Number Of Triples: " << totalNumberOfTriples << endl;
    cout << "Number Of Home Runs: " << totalNumberOfHomeRuns << endl;
    
    // Line 39 is doing a math problem so user can get the number of singles without entering it in themselves.
    
    totalNumberOfBases = totalNumberOfSingles + ( totalNumberOfDoubles * 2) + (totalNumberOfTriples * 3) + ( totalNumberOfHomeRuns * 4);
    cout << "Number Of Bases =" << totalNumberOfBases << endl;
    
    // Line 48 is doing another math problem so the user can figure out the number of bases without entering the value in themselves.
    
    // lines 41, 42, 43, 48, 44, and 49 are the converted values from the three math problems that had occured in this program.
    
    return 0;
}
