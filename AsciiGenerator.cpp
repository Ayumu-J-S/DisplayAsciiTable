/** @file AsciiGenerator.cpp

This is implememntation file for AsciiGenerator class.
@author Ayumu Saito
*/


#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
using namespace std;

#include "AsciiGenerator.h"
#include "utilities.h"
using Scobey::Pause;

//******************************************************************
AsciiGenerator::AsciiGenerator
(
    char firstChar, //in
    char lastChar   //in
)
{
    this->firstChar = firstChar;
    this->lastChar = lastChar;
}

//******************************************************************
void AsciiGenerator::displayHorizontally()
{
    system("clear");

    int gap = (int)lastChar - (int)firstChar;

    //Display the column head
    int copy = gap;
    int count = 0;
    cout << endl;
    while ((copy >= 0) && (count < 4))
    {
        cout << "     Dec Oct Hex";
        copy--;
        count++;
    }
    cout << endl;

    int charNum = gap + 1;
    int charCount = 0;
    int lineCount = 0;

    for (int i = firstChar; i <= lastChar; i++)
    {
        //Display the characters corresponding values
        cout << setw(4) << (char)i;
        cout << setw(4) << dec << i;
        cout << setw(4) << dec << oct << i;
        cout << setw(4) << dec << hex << uppercase << i;

        charCount++;

        //Add lineCount by 1 if the screen has 4 columns
        if (charCount % 4 == 0)
        {
            cout << endl;
            lineCount++;
        }

        //If the screen is full go to the next screen
        if ((lineCount > 0 && lineCount % 22 == 0) && charCount % 4 == 0)
        {
            Pause();

            //Display the column header for the next screen
            if (charNum > charCount)
            {
                int numCharNextScr = gap - charCount;
                int count = 0;
                while (numCharNextScr >= 0 && count < 4)
                {
                    cout << "     Dec Oct Hex";
                    numCharNextScr--;
                    count++;
                }
                cout << endl;
            }
        }
    } //end of for loop

    //Pause if it did not pause and exit functionif the last row has 4 columns
    if (charCount % 4 == 0)
    {
        if (lineCount % 22 != 0)
        {
            Pause();
        }
    }
    else
    {
        cout << endl;
        Pause();
    }
}

//******************************************************************
void AsciiGenerator::displayVertically()
{
    system("clear");

    int gap = (int)lastChar - (int)firstChar;
    int numChars = gap + 1;
    int numColHeader = (numChars > 4) ? 4 : numChars;
    int numLine = (numChars % 4 == 0) ? numChars / 4 : numChars / 4 + 1;
    int numRemainCol = numChars % 4;
    int numScreen = 1;

    cout << endl;
    //Display the column head
    for (int i = 0; i < numColHeader; i++)
    {
        cout << "     Dec Oct Hex";
    }
    cout << endl;

    //Display ascii code and corresponding values
    //Display the first character in the row and add numLine to it
    for (int i = (int)firstChar; i < firstChar + numLine; i++)
    {
        int currChar = i;      //Keep track of current Character
        if (numRemainCol == 0) //If the last row has exactly 4 columns
        {
            for (int j = 0; j < 4; j++)
            {
                cout << setw(4) << (char)currChar;
                cout << setw(4) << dec << currChar;
                cout << setw(4) << dec << oct << currChar;
                cout << setw(4) << dec << hex << uppercase << currChar;

                currChar = currChar + numLine;
            }
        }
        else //If the last row doesn't have exactly 4 columns
        {
            if ((i - firstChar + 1) != numLine)//If current line isn't last
            {
                for (int j = 0; j < 4; j++)
                {
                    cout << setw(4) << (char)currChar;
                    cout << setw(4) << dec << currChar;
                    cout << setw(4) << dec << oct << currChar;
                    cout << setw(4) << dec << hex << uppercase << currChar;

                    /*
                    Add numLine to currChar if the currentChar is on the
                    column that has extra ascii code in the end, Add
                    numLine to currChar and subtract 1 if not.
                    */
                    if (j < numRemainCol)
                    {
                        currChar = currChar + numLine;
                    }
                    else
                    {
                        currChar = currChar + numLine - 1;
                    }
                }
            }
            else //If the current line (i) is the last line
            {
                for (int j = 0; j < numRemainCol; j++)
                {
                    cout << setw(4) << (char)currChar;
                    cout << setw(4) << dec << currChar;
                    cout << setw(4) << dec << oct << currChar;
                    cout << setw(4) << dec << hex << uppercase << currChar;

                    currChar = currChar + numLine;
                }
            }
        }
        cout << endl;

        //If there are more lines, display the new column header
        if ((i - firstChar + 1) % 22 == 0 && numLine > 22)
        {
            Pause();

            int numRemainChars = numChars - 88 * numScreen;
            int numColHeader2 = (numRemainChars > 4) ? 4 : numRemainChars;

            //Display the next column header
            for (int i = 0; i < numColHeader2; i++)
            {
                cout << "     Dec Oct Hex";
            }
            cout << endl;
        }
    } //end of for loop

    //Pause to end the function
    Pause();
}
