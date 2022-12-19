#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>

using namespace std;

void printGrid(int sampleGrid[500][500])
{
    int tailCount = 0;
    //cout << "NEW GRID IS : " << endl;
    for(int i = 0; i < 500; i++)
    {
        for(int j = 0; j < 500; j++) 
        {
            // cout << sampleGrid[i][j];
            if(sampleGrid[i][j] == 1) tailCount++;
        }
        // cout << endl;
    }
    cout << "Tail count is " << tailCount << endl;
}
            
int main() 
{
    ifstream myFile("input.txt");
    string myString;
    int currHeadPositionX = 250, currHeadPositionY = 250, currTailPositionX = 250, currTailPositionY = 250;
    int grid[500][500] = {0};
    if (myFile.is_open()) 
    {
        while(myFile)
        {
            getline(myFile, myString);
            if (myString[0] == 'R')
            {
                for(int i = 0; i < atoi(&myString[2]); i++)
                {
                    currHeadPositionX++;
                    if(abs(currHeadPositionX - currTailPositionX) > 1)
                    {
                        // diagonal move
                        if((currHeadPositionX != currTailPositionX) && (currHeadPositionY != currTailPositionY))
                        {
                            currTailPositionX++;
                            if (currTailPositionY > currHeadPositionY) currTailPositionY--;
                            else if (currTailPositionY < currHeadPositionY) currTailPositionY++;
                        }
                        else 
                        {
                            currTailPositionX++;
                        }
                    }
                    grid[currTailPositionX][currTailPositionY] = 1;
                    // cout << "Current Head Position is : (" << currHeadPositionX << " , " << currHeadPositionY << ")" << endl;
                    // cout << "Current Tail Position is : (" << currTailPositionX << " , " << currTailPositionY << ")" << endl;
                }
            }
            if (myString[0] == 'U')
            {
                for(int j = 0; j < atoi(&myString[2]); j++)
                {
                    currHeadPositionY++;
                    if(abs(currHeadPositionY - currTailPositionY) > 1)
                    {
                        // diagonal move
                        if((currHeadPositionX != currTailPositionX) && (currHeadPositionY != currTailPositionY))
                        {
                            currTailPositionY++;
                            if (currTailPositionX < currHeadPositionX) currTailPositionX++;
                            else if (currTailPositionX > currHeadPositionX) currTailPositionX--;
                        }
                        else 
                        {
                            currTailPositionY++;
                        }
                    }
                    grid[currTailPositionX][currTailPositionY] = 1;
                    // cout << "Current Head Position is : (" << currHeadPositionX << " , " << currHeadPositionY << ")" << endl;
                    // cout << "Current Tail Position is : (" << currTailPositionX << " , " << currTailPositionY << ")" << endl;
                }
            }
            if (myString[0] == 'D')
            {
                for(int k = 0; k < atoi(&myString[2]); k++)
                {
                    currHeadPositionY--;
                    if(abs(currHeadPositionY - currTailPositionY) > 1)
                    {
                        // diagonal move
                        if((currHeadPositionX != currTailPositionX) && (currHeadPositionY != currTailPositionY))
                        {
                            currTailPositionY--;
                            if (currTailPositionX > currHeadPositionX) currTailPositionX--;
                            else if (currTailPositionX < currHeadPositionX) currTailPositionX++;
                        }
                        else 
                        {
                            currTailPositionY--;
                        }
                    }
                    grid[currTailPositionX][currTailPositionY] = 1;
                    // cout << "Current Head Position is : (" << currHeadPositionX << " , " << currHeadPositionY << ")" << endl;
                    // cout << "Current Tail Position is : (" << currTailPositionX << " , " << currTailPositionY << ")" << endl;
                }
            }
            if (myString[0] == 'L')
            {
                for(int l = 0; l < atoi(&myString[2]); l++)
                {
                    currHeadPositionX--;
                    if(abs(currHeadPositionX - currTailPositionX) > 1)
                    {
                        // diagonal move
                        if((currHeadPositionX != currTailPositionX) && (currHeadPositionY != currTailPositionY))
                        {
                            currTailPositionX--;
                            if (currTailPositionY > currHeadPositionY) currTailPositionY--;
                            else if (currTailPositionY < currHeadPositionY) currTailPositionY++;
                        }
                        else 
                        {
                            currTailPositionX--;
                        }
                    }
                    grid[currTailPositionX][currTailPositionY] = 1;
                    // cout << "Current Head Position is : (" << currHeadPositionX << " , " << currHeadPositionY << ")" << endl;
                    // cout << "Current Tail Position is : (" << currTailPositionX << " , " << currTailPositionY << ")" << endl;
                }
            }
        }
    }
    printGrid(grid);
    return 0;
}