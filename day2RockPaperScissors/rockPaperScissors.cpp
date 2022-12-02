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
            else if (myChar == 'X' || myChar == 'Y' || myChar == 'Z')
            {
                // draw
                if (theirPlay == 'A' && myChar == 'X') gameScore += 3;
                // draw
                else if (theirPlay == 'B' && myChar == 'Y') gameScore += 3;
                // draw
                else if (theirPlay == 'C' && myChar == 'Z') gameScore += 3;
                // win with rock
                else if (theirPlay == 'A' && myChar == 'Y') gameScore += 6;
                // win with paper 
                else if (theirPlay == 'B' && myChar == 'Z') gameScore += 6;
                // win with scissors
                else if (theirPlay == 'C' && myChar == 'X') gameScore += 6;
                // score through rock
                if (myChar == 'X') gameScore += 1;
                // score through paper
                else if (myChar == 'Y') gameScore += 2;
                // score through scissors
                else if (myChar == 'Z') gameScore += 3;
            }
        }
    }
    cout << "Total score is: " << totalScore;
    return 0;
}