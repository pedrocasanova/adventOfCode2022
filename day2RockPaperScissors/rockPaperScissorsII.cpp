#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int main() 
{
    string buf;
    ifstream myFile("input.txt");
    int gameScore = 0, totalScore = 0;
    if (myFile.is_open()) 
    {
        char myChar, theirPlay;
        while (myFile) 
        {
            myChar = myFile.get();
            if (myChar == '\n')
            {
                totalScore += gameScore;
                gameScore = 0;
            }
            else if (myChar == 'A' || myChar == 'B' || myChar == 'C')
            {
                theirPlay = myChar;
            }
            // Win scenario
            if (myChar == 'Z')
            {
                if (theirPlay == 'A') gameScore += 8;
                else if (theirPlay == 'B') gameScore += 9;
                else if (theirPlay == 'C') gameScore += 7;
            }
            // Draw scenario
            if (myChar == 'Y')
            {
                if (theirPlay == 'A') gameScore += 4;
                else if (theirPlay == 'B') gameScore += 5;
                else if (theirPlay == 'C') gameScore += 6;
            }
            // Lose scenario
            if (myChar == 'X')
            {
                if (theirPlay == 'A') gameScore += 3;
                else if (theirPlay == 'B') gameScore += 1;
                else if (theirPlay == 'C') gameScore += 2;
            }
        }
    }
    cout << "Total score is: " << totalScore;
    return 0;
}