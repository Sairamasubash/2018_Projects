/**********************************************************************************************************
 CSCI 240         Program 5     Fall 2018
 
 Programmer: Subash Muppalaneni
 
 Section: CSCI 240-2
 
 TA: Aparna
 
 Date Due: 10/12/18
 
 Purpose: The Purpose of this program is to create three loops (for, do while, while), and generate three sets of random numbers in the range of 50-to-100. Then, for each set, we have to count how many values fall into particular ranges.
 **********************************************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
int main()
{
    
    srand(1);       //Setting the random number generator seed to 1.
    
    const int UPPER_BOUNDARY = 100;
    const int LOWER_BOUNDARY = 50;
    const int COUNT = 10;
    
    //Lines 23-25 is where the symbolic constants are stated.
    
    int number, range = 0, point1, point2, point3, point4, point5, point6, range1, range2, range3, range4, range5, range6, count1, count2, count3, count4, count5, count6, total1, total2, total3, total4, total5, total6;
    
        point1 = 0;
        point2 = 0;
        point3 = 0;
        point4 = 0;
        point5 = 0;
        point6 = 0;
    
    //Lines 29-36 is where the integer variables are stated and declared.
    
        cout << "Set 1: " << endl;
    
    
    for(number = 1; number <= COUNT; number ++)    //For loop is starting
    {
    
        range = LOWER_BOUNDARY + (rand() % (UPPER_BOUNDARY - LOWER_BOUNDARY + 1));    //The calculation of the range.
        cout << "\t" << range << "     ";
        
    if (range == 100)
    {
        point1++;
    }
    else if (range <= 99 && range >= 90)
    {
        point2++;
    }
    else if (range <= 89 && range >= 80)
    {
        point3++;
    }
    else if (range <= 79 && range >= 70)
    {
        point4++;
    }
    else if (range <= 69 && range >= 60)
    {
        point5++;
    }
    else if (range <= 59 && range >= 50)
    {
        point6++;
    }
    }
    
    //Lines 49-73 is where the cascading if statement made for the ranges in the for loop.
    
        cout << "\n\n100 count: " << point1 << "   90's count: " << point2 << "   80's count: " << point3 << "   70's count: " << point4 << "   60's count: " << point5 << "   50's count: " << point6 << endl << endl << endl;
    
    //Line 77 is the output of the range counters.
    
        range1 = 0;
        range2 = 0;
        range3 = 0;
        range4 = 0;
        range5 = 0;
        range6 = 0;
    
    //Lines 81-86 is where the integer variables are redeclared for the second time.
    
        cout << "set 2: " << endl;
    
        number = 1;
    
    while (number <= COUNT)  //Start of the while loop.
    {
        
        range = LOWER_BOUNDARY + (rand() % (UPPER_BOUNDARY - LOWER_BOUNDARY + 1));  //The calculation of the range.
        cout << "\t" << range << "     ";
        number++;
        
    if (range == 100)
    {
        range1++;
    }
    else if (range <= 99 && range >= 90)
    {
        range2++;
    }
    else if (range <= 89 && range >= 80)
    {
        range3++;
    }
    else if (range <= 79 && range >= 70)
    {
        range4++;
    }
    else if (range <= 69 && range >= 60)
    {
        range5++;
    }
    else if (range <= 59 && range >= 50)
    {
        range6++;
    }
    }
    
    //Lines 101-125 is where the cascading if statement made for the ranges in the while loop.
    
        cout << "\n\n100 count: " << range1 << "   90's count: " << range2 << "   80's count: " << range3 << "   70's count: " << range4 << "   60's count: " << range5 << "   50's count: " << range6 << endl << endl << endl;
    
     //Line 129 is the second output of the range counters.
    
        count1 = 0;
        count2 = 0;
        count3 = 0;
        count4 = 0;
        count5 = 0;
        count6 = 0;
    
    //Lines 133-138 is where the integer variables are redeclared for the third time.
    
        cout << "set 3: " << endl;
    
        number = 1;
    
    do{                        //Starting the do while loop.
        
        range = LOWER_BOUNDARY + (rand() % (UPPER_BOUNDARY - LOWER_BOUNDARY + 1));    //The calculation of the range.
        cout << "\t" << range << "     ";
        number++;
        
    if (range == 100)
    {
        count1++;
    }
    else if (range <= 99 && range >= 90)
    {
        count2++;
    }
    else if (range <= 89 && range >= 80)
    {
        count3++;
    }
    else if (range <= 79 && range >= 70)
    {
        count4++;
    }
    else if (range <= 69 && range >= 60)
    {
        count5++;
    }
    else if (range <= 59 && range >= 50)
    {
        count6++;
    }
        
    } while (number <= COUNT);
    
    //Lines 146-177 is where the cascading if statement made for the ranges in the do while loop.
    
        cout << "\n\n100 count: " << count1 << "   90's count: " << count2 << "   80's count: " << count3 << "   70's count: " << count4 << "   60's count: " << count5 << "   50's count: " << count6 << endl << endl << endl;
    
    //Line 182 is the third output of the range counters.
        
    //******* START OF THE EXTRA CREDIT *******.
    
        total1 = point1 + range1 + count1;
        total2 = point2 + range2 + count2;
        total3 = point3 + range3 + count3;
        total4 = point4 + range4 + count4;
        total5 = point5 + range5 + count5;
        total6 = point6 + range6 + count6;
    
    //Lines 185-190 is where the total integers are declared
    
        cout << "Overall Counts" << endl;
        cout << "100  count:   " << total1 << endl;
        cout << "90's count:   " << total2 << "   ****" << endl;
        cout << "80's count:   " << total3 << "   *****" << endl;
        cout << "70's count:   " << total4 << "   ******" << endl;
        cout << "60's count:   " << total5 << "   ********" << endl;
        cout << "50's count:   " << total6 << "   *******" << endl << endl << endl;
    
    //Lines 196-202 is where the total values of the three loops are outputed.
    
    return 0;
    
}










