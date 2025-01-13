/**********************************************************************************************************
 CSCI 240         Program 3     Fall 2018
 
 Programmer: Subash Muppalaneni
 
 Section: CSCI 240-2
 
 Date Due: 9/21/18
 
 Purpose: This program gives the user their monthly phone bill depending on what package they chose previously ( A, B, C ).
 **********************************************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
int TotalNumberOfMinutes;
double MonthlyBill;
char SubscriptionPackage;
cout<<fixed<<setprecision(2);

    // Lines 18-21 is where the integers, doubles, and characters are declared. It is also where the setprecision is set.
    
    cout<< "Which cell phone carrier package do you have (A, B, or C)? ";
    cin>> SubscriptionPackage;
    
    cout<< "How many minutes have you used this month? ";
    cin>> TotalNumberOfMinutes;
    
    // Lines 25-29 is where the user enters the subscription package that they have(A,B,C), and the total number of minutes they used that month.
    
if (TotalNumberOfMinutes < 0 )
{
    cout<< " YOU HAVE ENTERED AN INVALID TOTAL NUMBER OF MINUTES, PLEASE ENTER A NEW NUMBER: ";
    cin>> TotalNumberOfMinutes;
    
    // Lines 35 and 36 is where the user is informed that they had entered an invalid number, if they entered anything below 0.
}
    
if ( SubscriptionPackage == 'A') // First subscription package.
{
if ( TotalNumberOfMinutes > 300)
        
{
    MonthlyBill = 29.99 + ((TotalNumberOfMinutes - 300) * 0.32 ); // Calculation for the first subscription package.
}
else
{
    MonthlyBill = 29.99;
}
    cout<< "\nThe monthly bill for subscription package A is $"<< MonthlyBill << endl;
}
else if ( SubscriptionPackage == 'B') // Second subscription package.
{
if ( TotalNumberOfMinutes > 750)
{
    MonthlyBill = 49.99 + ((TotalNumberOfMinutes - 750) * 0.28 ); // Calculation for the second subscription package.
}
else
{
    MonthlyBill = 49.99;
}
    cout<< "\nThe monthly bill for subscription package B is $"<< MonthlyBill << endl;
}
else if ( SubscriptionPackage == 'C') // // Third subscription package.
{
    cout<< "\nThe monthly bill for subscription package C is $59.99"<< endl;

// Lines 46, 50, and 62 is where the prices of the three subscription packages are stated.

// Lines 52, 64, and 68 is where the users total phone bill for that month is shown.
    
}
return 0;
}


