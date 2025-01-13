/***********************************************************************
 CSCI 240         Program 9     Fall 2018
 
 Programmer: Subash Muppalaneni(Z1844762)
 
 Section: CSCI 240-2
 
 TA: Pravalika
 
 Date Due: 11/30/18
 
 Purpose: The purpose of this program is to creat a class called "LoShuMagicSquare" that contains a couple of different methods or functions. These methods will tell the user if the numbers in the puzzle text file contain a magic square (there are a total of 4 puzzle text file for this program).
 ***********************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

//Place the class definition after this line

class LoShuMagicSquare
{
public:
    
    int array [3][3];
    
    LoShuMagicSquare();
    
    void printSquare();
    
    void fillSquare(const char filename[]);

    bool isMagic();
    
};

LoShuMagicSquare :: LoShuMagicSquare()
{
    int j,i;
    
    for (i = 0; i < 3; i++)
    {
        
        
        for (j = 0; j < 3; j++)
        {
            array[i][j] = 0;
        }
    }
}


void LoShuMagicSquare :: printSquare()
{
    int j,i;
    
    for (i = 0; i < 3; i++)
    {
        
        for (j = 0; j < 3; j++)
        {
            cout << array[i][j]<<" ";
        }
        cout << endl;
    }
    
}


void LoShuMagicSquare:: fillSquare(const char filename[])
{
    int j,i;
    int value;
    ifstream infile3;
    
    infile3.open(filename);
    
    if(infile3.fail())
    {
        cout << "\t\t\t\t*****THE INPUT FILE DID NOT OPEN*****\n" << endl;
        exit(-1);
    }
    
    infile3 >> value;
    
    while (infile3)
    {
        
        for (i = 0; i < 3; i++)
        {
            
            for (j = 0; j < 3; j++)
            {
                array[i][j] = value;
                infile3 >> value;
            }
        }
        
    }
    
    infile3.close();
}


bool LoShuMagicSquare:: isMagic()
{
    int sum1 = array[0][0] + array [0][1] + array[0][2];
    int sum2 = array[1][0] + array [1][1] + array[1][2];
    int sum3 = array[2][0] + array [2][1] + array[2][2];
    int sum4 = array[0][0] + array [1][0] + array[2][0];
    int sum5 = array[0][1] + array [1][1] + array[2][1];
    int sum6 = array[0][2] + array [1][2] + array[2][2];
    int sum7 = array[0][0] + array [1][1] + array[2][2];
    int sum8 = array[0][2] + array [1][1] + array[2][0];
    int i,j,k,l;
    
    
    if (sum1==15 and sum1 == sum2 && sum2 == sum3 && sum3 == sum4 && sum4 == sum5 && sum5 == sum6 && sum6 == sum7 && sum7 == sum8)
    {
    
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                int number = array[i][j];
                for (k = j + 1; k < 3; k++)
                {
                    if (number == array[i][k] || number > 3 * 3 || number < 1)
                    {
                        return false;
                    }
                }
            
                for (l = i + 1; l < 3; l++)
                {
                    if (number == array[l][j] || number > 3 * 3 || number < 1)
                    {
                        return false;
                    }
                }
            }
        }
    }
            
    
        return true;
}


int main()
{
    
    LoShuMagicSquare puzzle;
    
    cout << "Starting Puzzle values:" << endl << endl;
    
    puzzle.printSquare();
    
    cout << endl << endl << "Puzzle 1:" << endl << endl;
    
    puzzle.fillSquare("/Users/subashmuppalaneni/Desktop/loshu_puzzle1.txt");
    
    puzzle.printSquare();
    
    cout << endl << "Is it magic? " << ( puzzle.isMagic() ? "Yes": "No" ) << endl << endl << endl;
    
    
    
    cout << "Puzzle 2:" << endl << endl;
    
    puzzle.fillSquare( "/Users/subashmuppalaneni/Desktop/loshu_puzzle2.txt");
    
    puzzle.printSquare();
    
    cout << endl << "Is it magic? " << ( puzzle.isMagic() ? "Yes": "No" ) << endl << endl << endl;
    
    
   
    cout << "Puzzle 3:" << endl << endl;
    
    puzzle.fillSquare( "/Users/subashmuppalaneni/Desktop/loshu_puzzle3.txt");
    
    puzzle.printSquare();
    
    cout << endl << "Is it magic? " << ( puzzle.isMagic() ? "Yes": "No" ) << endl << endl << endl;
    
    
    
    cout << "Puzzle 4:" << endl << endl;
    
    puzzle.fillSquare( "/Users/subashmuppalaneni/Desktop/loshu_puzzle4.txt");
    
    puzzle.printSquare();
    
    cout << endl << "Is it magic? " << ( puzzle.isMagic() ? "Yes": "No" ) << endl << endl << endl;
    
    
    return 0;
}
