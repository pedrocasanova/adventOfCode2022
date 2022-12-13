#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>

using namespace std;

void printGrid(int sampleGrid[20][20])
{
    cout << "NEW GRID IS : " << endl;
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++) cout << sampleGrid[i][j];
        cout << endl;
    }
}
            
int main() 
{
    ifstream myFile("input.txt");
    string myString;
    int currHeadPositionX = 0, currHeadPositionY = 0, currTailPositionX = 0, currTailPositionY = 0;
    int grid[20][20] = {0};
    if (myFile.is_open()) 
    {
        while(myFile)
        {
            getline(myFile, myString);
            if (myString[0] == 'R')
            {
                for(int j = 0; j < atoi(&myString[2]); j++)
                {
                    currHeadPositionX++;
                    grid[currHeadPositionX][currHeadPositionY] = 1;
                }
            }
            if (myString[0] == 'U')
            {
                for(int i = 0; i < atoi(&myString[2]); i++)
                {
                    currHeadPositionY++;
                    grid[currHeadPositionX][currHeadPositionY] = 2;
                }
            }
            if (myString[0] == 'D')
            {
                for(int m = 0; m < atoi(&myString[2]); m++)
                {
                    currHeadPositionY--;
                    grid[currHeadPositionX][currHeadPositionY] = 3;
                }
            }
            if (myString[0] == 'L')
            {
                for(int n = 0; n < atoi(&myString[2]); n++)
                {
                    currHeadPositionX--;
                    grid[currHeadPositionX][currHeadPositionY] = 4;
                }
            }
        }
        printGrid(grid);
    }
    return 0;
}