/***************************************************************
 CSCI 240         Program 2     Fall 2018
 
 Programmer: Subash Muppalaneni
 
 Section: CSCI 240-2
 
 Date Due: 9/14/18
 
 Purpose: This program adds on to program 1 by calculating the slugging percentage of the baseball player.
 ***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    
    int totalNumberOfHits, totalNumberOfDoubles, totalNumberOfTriples, totalNumberOfHomeRuns, totalNumberOfSingles, totalNumberOfBases, totalNumberOfAtBats;
    
    double sluggingPercentage;
    
    // Lines 20-22 are all of the interger values (there can be no decimals), and my double values (there can be decimals).
    
    cout << "Enter the number of hits: ";
    cin >> totalNumberOfHits;
    
    cout << "Enter the number of doubles: ";
    cin >> totalNumberOfDoubles;
    
    cout << "Enter the number of triples: ";
    cin >> totalNumberOfTriples;
    
    cout << "Enter the number of home runs: ";
    cin >> totalNumberOfHomeRuns;
    
    cout << "Enter the number of At Bats: ";
    cin >> totalNumberOfAtBats;
    
    // Lines 26-39 are all asking the user to enter an integer, so lines could take the integers and convert them into the integer values from line 20.
    
    totalNumberOfSingles = totalNumberOfHits - totalNumberOfDoubles - totalNumberOfTriples - totalNumberOfHomeRuns;
    
    cout << "Number Of Singles:" << totalNumberOfSingles << endl;
    cout << "Number Of doubles: " << totalNumberOfDoubles << endl;
    cout << "Number Of Triples: " << totalNumberOfTriples << endl;
    cout << "Number Of Home Runs: " << totalNumberOfHomeRuns << endl;
    
    // Line 43 is doing a math problem so user can get the number of singles without entering it in themselves.
    
    totalNumberOfBases = totalNumberOfSingles + ( totalNumberOfDoubles * 2) + (totalNumberOfTriples * 3) + ( totalNumberOfHomeRuns * 4);
    cout << "Number Of Bases = " << totalNumberOfBases << endl;
    
    // Line 52 is doing another math problem so the user can figure out the number of bases without entering the value in themselves.
    
    sluggingPercentage = totalNumberOfBases / (double)totalNumberOfAtBats;
    cout << "Players Slugging Percentage: " << fixed << setprecision(3) << sluggingPercentage << endl;
    
    // line 57 is doing one last math problem so the user can find out the batters slugging percentage without entering it in physically.
    
    // lines 45, 46, 47, 48, 53, and 58 are the converted values from the three math problems that had occured in this program.
    
    return 0;
}
