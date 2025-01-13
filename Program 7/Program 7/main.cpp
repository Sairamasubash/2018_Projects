/****************************************************************************************************
 CSCI 240         Program 7     Fall 2018
 
 Programmer: Subash Muppalaneni(Z1844762)
 
 Section: CSCI 240-2
 
 TA: Abdul
 
 Date Due: 11/2/18
 
 Purpose: The purpose of this program is to process a file containing the stanley cup winners between 1927 and 2018.
 After, we allow the user to request a team and tell him the number of times his requested team won the stanley cup between 1927 and 2018.
 ****************************************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

int buildArray(string team_array[]);
int numWins(string team_array[], int numTeams, string search_team);
void displayTeams( string team_array[], int numTeams );

/***************************************************************
 Function: main
 
 Use: This is where we test if the program is running correctly, and this is also where every other function in the program is called. in this function, we are also getting the users requested teams.
 
 Arguments: None
 
 Returns: 1. return 0: whenever we get the return value of 0 in the output, we can then confirm that our program was successful.
 
 Note: This is the main body of the entire program because this is where everything runs through.
 ***************************************************************/

int main()   // Start of the main function.
{
    
    string requestedTeam;
    const int MAXIMIUM_TEAMS_IN_ARRAY = 100;
    string NHlChampionsArray[MAXIMIUM_TEAMS_IN_ARRAY];
    int numberOfTeamsInArray, numberOfTimesEachTeamWon;
    
    // Lines 43-46 is where all of my data types are declared.
    
    numberOfTeamsInArray = buildArray(NHlChampionsArray);
    
    cout << "There are " << numberOfTeamsInArray << " teams in the input file\n";
    
    cout << "\nTeam? ";
    
    getline(cin, requestedTeam);  // Where we get the users requested teams.
    
    if(requestedTeam == "Not Awarded")
    {
        cout << "\nThe Stanley Cup was not awarded " << numWins(NHlChampionsArray,  numberOfTeamsInArray, requestedTeam) << " time(s).\n";
    }
    else
    {
        cout << "\nThe " << requestedTeam << " have won the Stanley Cup " << numWins(NHlChampionsArray,  numberOfTeamsInArray, requestedTeam) << " time(s).\n";
    }
    
    // Lines 59-66 is the if statement to check what the users requested.
    
    displayTeams(NHlChampionsArray, numberOfTeamsInArray);
    
    return 0;  //Checking if the program ran correctly.
}

/***************************************************************
 Function: buildArray
 
 Use: The buildArray function checks how many teams are in the input file and outpuths the exact number. It also checks if the input file correctly opened or if the input file failed.
 
 Arguments: 1. teamNameArray[]
 
 Returns: 1. return i: returns the total number of NHL teams in the input file.
 
 Note: this in the first function that i included after the main function.
 ***************************************************************/

int buildArray(string teamNameArray[])    // Start of the buildArray function.
{
    int i = 0;
    ifstream infile2;
    infile2.open( "NHL_Championship.txt" );
    
    if(infile2.fail())
    {
        cout << "\t\t\t\t*****THE INPUT FILE DID NOT OPEN*****\n" << endl;
        exit(-1);
    }
    cout << "\t\t\t\t*****THE INPUT FILE OPENED*****\n" << endl;
    
    //Lines 93-98 is where we check if the file opened correctly.
    
    getline(infile2,teamNameArray[i]);
    
    while (infile2)
    {
        
        i++;
        
        getline(infile2,teamNameArray[i]);
        
    }
    
    // Lines 104-111 are adding the the total number of teams in the file.
    
    return i;     // Returning the total number of champions between 1927 and 2018.
    
}

/***************************************************************
 Function: numWins
 
 Use: The numWins function is checking the users requested team and outputing the number of times that team won the stanley cup.
 
 Arguments: 1. team_array[]
 2. numTeams
 3. search_team
 
 Returns: 1. return count: returns the total number of times the requested team won the stanley cup.
 
 Note: this in the second function that i included after the main function.
 ***************************************************************/

int numWins(string team_array[], int numTeams, string search_team)  // Start of the numWins functions.
{
    int count = 0;
    
    for (int i = 0; i < numTeams; i++)
    {
        if(team_array[i] == search_team)
        {
            count++;
        }
    }
    
    // Lines 137-143 Adding the number of time the requested team won.
    
    return count;        // Returning the number of times the requested teams won the stanley cup.
    
}

/***************************************************************
 Function: displayTeams
 
 Use: the displayTeams function tells the user the exact year that the requested team won
 
 Arguments: 1. team_array[]
 2. numTeams
 
 Returns: None
 
 Note: this in the third function that i included after the main function.
 ***************************************************************/

void displayTeams( string team_array[], int numTeams )
{
    int year = 1927;
    
    cout << "\nAll of the teams that have won the stanley cup" << endl;
    
    cout << "-----------------------------------------------" << endl;
    
    for(int i = 0; i < numTeams; i++)
    {
        
        cout << year << "   " << team_array[i] << endl;
        
        year++;
        
    }
    
}


