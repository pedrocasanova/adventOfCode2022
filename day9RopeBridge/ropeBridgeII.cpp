#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>

#define SIZE     1000
#define MIDPOINT SIZE/2

using namespace std;

void printGrid(char sampleGrid[SIZE][SIZE])
{
    int tailCount = 0;
    //cout << "NEW GRID IS : " << endl;
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++) 
        {
        //    cout << sampleGrid[i][j];
            if(sampleGrid[i][j] == '#') tailCount++;
        }
        // cout << endl;
    }
    cout << "Tail count is " << tailCount << endl;
}

void initGrid(char sampleGrid[SIZE][SIZE])
{
    int tailCount = 0;
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++) 
        {
            sampleGrid[i][j] = '.';
        }
    }
}

int main() 
{
    ifstream myFile("input.txt");
    string myString;
    int currHeadPositionX = MIDPOINT, currHeadPositionY = MIDPOINT;
    int currTail1PositionX = MIDPOINT, currTail1PositionY = MIDPOINT, currTail2PositionX = MIDPOINT, currTail2PositionY = MIDPOINT, currTail3PositionX = MIDPOINT, currTail3PositionY = MIDPOINT;
    int currTail4PositionX = MIDPOINT, currTail4PositionY = MIDPOINT, currTail5PositionX = MIDPOINT, currTail5PositionY = MIDPOINT, currTail6PositionX = MIDPOINT, currTail6PositionY = MIDPOINT;
    int currTail7PositionX = MIDPOINT, currTail7PositionY = MIDPOINT, currTail8PositionX = MIDPOINT, currTail8PositionY = MIDPOINT, currTail9PositionX = MIDPOINT, currTail9PositionY = MIDPOINT;
    char grid[SIZE][SIZE] = {'.'};
    initGrid(grid);
    if (myFile.is_open()) 
    {
        while(myFile)
        {
            grid[MIDPOINT][MIDPOINT] = 's';
            getline(myFile, myString);
            if (myString[0] == 'R')
            {
                for(int i = 0; i < atoi(&myString[2]); i++)
                {
                    currHeadPositionX++;
                    if(abs(currHeadPositionX - currTail1PositionX) > 1)
                    {
                        // diagonal move
                        if((currHeadPositionX != currTail1PositionX) && (currHeadPositionY != currTail1PositionY))
                        {
                            currTail1PositionX++;
                            if (currTail1PositionY > currHeadPositionY) currTail1PositionY--;
                            else if (currTail1PositionY < currHeadPositionY) currTail1PositionY++;
                        }
                        else 
                        {
                            currTail1PositionX++;
                        }
                    }
                    if(abs(currTail1PositionX - currTail2PositionX) > 1)
                    {
                        // diagonal move
                        if((currTail1PositionX != currTail2PositionX) && (currTail1PositionY != currTail2PositionY))
                        {
                            currTail2PositionX++;
                            if (currTail2PositionY > currTail1PositionY) currTail2PositionY--;
                            else if (currTail2PositionY < currTail1PositionY) currTail2PositionY++;
                        }
                        else 
                        {
                            currTail2PositionX++;
                        }
                    }
                    if(abs(currTail3PositionX - currTail2PositionX) > 1)
                    {
                        // diagonal move
                        if((currTail3PositionX != currTail2PositionX) && (currTail3PositionY != currTail2PositionY))
                        {
                            currTail3PositionX++;
                            if (currTail3PositionY > currTail2PositionY) currTail3PositionY--;
                            else if (currTail3PositionY < currTail2PositionY) currTail3PositionY++;
                        }
                        else 
                        {
                            currTail3PositionX++;
                        }
                    }
                    if(abs(currTail4PositionX - currTail3PositionX) > 1)
                    {
                        // diagonal move
                        if((currTail4PositionX != currTail3PositionX) && (currTail4PositionY != currTail3PositionY))
                        {
                            currTail4PositionX++;
                            if (currTail4PositionY > currTail3PositionY) currTail4PositionY--;
                            else if (currTail4PositionY < currTail3PositionY) currTail4PositionY++;
                        }
                        else 
                        {
                            currTail4PositionX++;
                        }
                    }
                    if(abs(currTail5PositionX - currTail4PositionX) > 1)
                    {
                        // diagonal move
                        if((currTail5PositionX != currTail4PositionX) && (currTail5PositionY != currTail4PositionY))
                        {
                            currTail5PositionX++;
                            if (currTail5PositionY > currTail4PositionY) currTail5PositionY--;
                            else if (currTail5PositionY < currTail4PositionY) currTail5PositionY++;
                        }
                        else 
                        {
                            currTail5PositionX++;
                        }
                    }
                    if(abs(currTail6PositionX - currTail5PositionX) > 1)
                    {
                        // diagonal move
                        if((currTail6PositionX != currTail5PositionX) && (currTail6PositionY != currTail5PositionY))
                        {
                            currTail6PositionX++;
                            if (currTail6PositionY > currTail5PositionY) currTail6PositionY--;
                            else if (currTail6PositionY < currTail5PositionY) currTail6PositionY++;
                        }
                        else 
                        {
                            currTail6PositionX++;
                        }
                    }
                    if(abs(currTail7PositionX - currTail6PositionX) > 1)
                    {
                        // diagonal move
                        if((currTail7PositionX != currTail6PositionX) && (currTail7PositionY != currTail6PositionY))
                        {
                            currTail7PositionX++;
                            if (currTail7PositionY > currTail6PositionY) currTail7PositionY--;
                            else if (currTail7PositionY < currTail6PositionY) currTail7PositionY++;
                        }
                        else 
                        {
                            currTail7PositionX++;
                        }
                    }
                    if(abs(currTail8PositionX - currTail7PositionX) > 1)
                    {
                        // diagonal move
                        if((currTail8PositionX != currTail7PositionX) && (currTail8PositionY != currTail7PositionY))
                        {
                            currTail8PositionX++;
                            if (currTail8PositionY > currTail7PositionY) currTail8PositionY--;
                            else if (currTail8PositionY < currTail7PositionY) currTail8PositionY++;
                        }
                        else 
                        {
                            currTail8PositionX++;
                        }
                    }
                    if(abs(currTail9PositionX - currTail8PositionX) > 1)
                    {
                        // diagonal move
                        if((currTail9PositionX != currTail8PositionX) && (currTail9PositionY != currTail8PositionY))
                        {
                            currTail9PositionX++;
                            if (currTail9PositionY > currTail8PositionY) currTail9PositionY--;
                            else if (currTail9PositionY < currTail8PositionY) currTail9PositionY++;
                        }
                        else 
                        {
                            currTail9PositionX++;
                        }
                    }
                    grid[currHeadPositionX][currHeadPositionY] = 'H';
                    grid[currTail1PositionX][currTail1PositionY] = '1';
                    grid[currTail2PositionX][currTail2PositionY] = '2';
                    grid[currTail3PositionX][currTail3PositionY] = '3';
                    grid[currTail4PositionX][currTail4PositionY] = '4';
                    grid[currTail5PositionX][currTail5PositionY] = '5';
                    grid[currTail6PositionX][currTail6PositionY] = '6';
                    grid[currTail7PositionX][currTail7PositionY] = '7';
                    grid[currTail8PositionX][currTail8PositionY] = '8';
                    grid[currTail9PositionX][currTail9PositionY] = '#';
                    // cout << "Current Head Position is : (" << currHeadPositionX << " , " << currHeadPositionY << ")" << endl;
                    // cout << "Current Tail 1 Position is : (" << currTail1PositionX << " , " << currTail1PositionY << ")" << endl;
                    // cout << "Current Tail 2 Position is : (" << currTail2PositionX << " , " << currTail2PositionY << ")" << endl;
                    // cout << "Current Tail 3 Position is : (" << currTail3PositionX << " , " << currTail3PositionY << ")" << endl;
                    // cout << "Current Tail 4 Position is : (" << currTail4PositionX << " , " << currTail4PositionY << ")" << endl;
                    // cout << "Current Tail 5 Position is : (" << currTail5PositionX << " , " << currTail5PositionY << ")" << endl;
                    // cout << "Current Tail 6 Position is : (" << currTail6PositionX << " , " << currTail6PositionY << ")" << endl;
                    // cout << "Current Tail 7 Position is : (" << currTail7PositionX << " , " << currTail7PositionY << ")" << endl;
                    // cout << "Current Tail 8 Position is : (" << currTail8PositionX << " , " << currTail8PositionY << ")" << endl;
                    // cout << "Current Tail 9 Position is : (" << currTail9PositionX << " , " << currTail9PositionY << ")" << endl;
                    // printGrid(grid);
                }
            }
            if (myString[0] == 'U')
            {
                for(int j = 0; j < atoi(&myString[2]); j++)
                {
                    currHeadPositionY++;
                    if(abs(currHeadPositionY - currTail1PositionY) > 1)
                    {
                        // diagonal move
                        if((currHeadPositionX != currTail1PositionX) && (currHeadPositionY != currTail1PositionY))
                        {
                            currTail1PositionY++;
                            if (currTail1PositionX < currHeadPositionX) currTail1PositionX++;
                            else if (currTail1PositionX > currHeadPositionX) currTail1PositionX--;
                        }
                        else 
                        {
                            currTail1PositionY++;
                        }
                    }
                    if(abs(currTail2PositionY - currTail1PositionY) > 1)
                    {
                        // diagonal move
                        if((currTail1PositionX != currTail2PositionX) && (currTail1PositionY != currTail2PositionY))
                        {
                            currTail2PositionY++;
                            if (currTail2PositionX < currTail1PositionX) currTail2PositionX++;
                            else if (currTail2PositionX > currTail1PositionX) currTail2PositionX--;
                        }
                        else 
                        {
                            currTail2PositionY++;
                        }
                    }
                    if(abs(currTail3PositionY - currTail2PositionY) > 1)
                    {
                        // diagonal move
                        if((currTail3PositionY != currTail2PositionX) && (currTail3PositionY != currTail2PositionY))
                        {
                            currTail3PositionY++;
                            if (currTail3PositionX < currTail2PositionX) currTail3PositionX++;
                            else if (currTail3PositionX > currTail2PositionX) currTail3PositionX--;
                        }
                        else 
                        {
                            currTail3PositionY++;
                        }
                    }
                    if(abs(currTail4PositionY - currTail3PositionY) > 1)
                    {
                        // diagonal move
                        if((currTail4PositionY != currTail3PositionX) && (currTail4PositionY != currTail3PositionY))
                        {
                            currTail4PositionY++;
                            if (currTail4PositionX < currTail3PositionX) currTail4PositionX++;
                            else if (currTail4PositionX > currTail3PositionX) currTail4PositionX--;
                        }
                        else 
                        {
                            currTail4PositionY++;
                        }
                    }
                    if(abs(currTail5PositionY - currTail4PositionY) > 1)
                    {
                        // diagonal move
                        if((currTail5PositionY != currTail4PositionX) && (currTail5PositionY != currTail4PositionY))
                        {
                            currTail5PositionY++;
                            if (currTail5PositionX < currTail4PositionX) currTail5PositionX++;
                            else if (currTail5PositionX > currTail4PositionX) currTail5PositionX--;
                        }
                        else 
                        {
                            currTail5PositionY++;
                        }
                    }
                    if(abs(currTail6PositionY - currTail5PositionY) > 1)
                    {
                        // diagonal move
                        if((currTail6PositionY != currTail5PositionX) && (currTail6PositionY != currTail5PositionY))
                        {
                            currTail6PositionY++;
                            if (currTail6PositionX < currTail5PositionX) currTail6PositionX++;
                            else if (currTail6PositionX > currTail5PositionX) currTail6PositionX--;
                        }
                        else 
                        {
                            currTail6PositionY++;
                        }
                    }
                    if(abs(currTail7PositionY - currTail6PositionY) > 1)
                    {
                        // diagonal move
                        if((currTail7PositionY != currTail6PositionX) && (currTail7PositionY != currTail6PositionY))
                        {
                            currTail7PositionY++;
                            if (currTail7PositionX < currTail6PositionX) currTail7PositionX++;
                            else if (currTail7PositionX > currTail6PositionX) currTail7PositionX--;
                        }
                        else 
                        {
                            currTail7PositionY++;
                        }
                    }
                    if(abs(currTail8PositionY - currTail7PositionY) > 1)
                    {
                        // diagonal move
                        if((currTail8PositionY != currTail7PositionX) && (currTail8PositionY != currTail7PositionY))
                        {
                            currTail8PositionY++;
                            if (currTail8PositionX < currTail7PositionX) currTail8PositionX++;
                            else if (currTail8PositionX > currTail7PositionX) currTail8PositionX--;
                        }
                        else 
                        {
                            currTail8PositionY++;
                        }
                    }
                    if(abs(currTail9PositionY - currTail8PositionY) > 1)
                    {
                        // diagonal move
                        if((currTail9PositionY != currTail8PositionX) && (currTail9PositionY != currTail8PositionY))
                        {
                            currTail9PositionY++;
                            if (currTail9PositionX < currTail8PositionX) currTail9PositionX++;
                            else if (currTail9PositionX > currTail8PositionX) currTail9PositionX--;
                        }
                        else 
                        {
                            currTail9PositionY++;
                        }
                    }
                    grid[currHeadPositionX][currHeadPositionY] = 'H';
                    grid[currTail1PositionX][currTail1PositionY] = '1';
                    grid[currTail2PositionX][currTail2PositionY] = '2';
                    grid[currTail3PositionX][currTail3PositionY] = '3';
                    grid[currTail4PositionX][currTail4PositionY] = '4';
                    grid[currTail5PositionX][currTail5PositionY] = '5';
                    grid[currTail6PositionX][currTail6PositionY] = '6';
                    grid[currTail7PositionX][currTail7PositionY] = '7';
                    grid[currTail8PositionX][currTail8PositionY] = '8';
                    grid[currTail9PositionX][currTail9PositionY] = '#';
                    // cout << "Current Head Position is : (" << currHeadPositionX << " , " << currHeadPositionY << ")" << endl;
                    // cout << "Current Tail 1 Position is : (" << currTail1PositionX << " , " << currTail1PositionY << ")" << endl;
                    // cout << "Current Tail 2 Position is : (" << currTail2PositionX << " , " << currTail2PositionY << ")" << endl;
                    // cout << "Current Tail 3 Position is : (" << currTail3PositionX << " , " << currTail3PositionY << ")" << endl;
                    // cout << "Current Tail 4 Position is : (" << currTail4PositionX << " , " << currTail4PositionY << ")" << endl;
                    // cout << "Current Tail 5 Position is : (" << currTail5PositionX << " , " << currTail5PositionY << ")" << endl;
                    // cout << "Current Tail 6 Position is : (" << currTail6PositionX << " , " << currTail6PositionY << ")" << endl;
                    // cout << "Current Tail 7 Position is : (" << currTail7PositionX << " , " << currTail7PositionY << ")" << endl;
                    // cout << "Current Tail 8 Position is : (" << currTail8PositionX << " , " << currTail8PositionY << ")" << endl;
                    // cout << "Current Tail 9 Position is : (" << currTail9PositionX << " , " << currTail9PositionY << ")" << endl;
                    // printGrid(grid);
                }
            }
            if (myString[0] == 'D')
            {
                for(int k = 0; k < atoi(&myString[2]); k++)
                {
                    currHeadPositionY--;
                    if(abs(currHeadPositionY - currTail1PositionY) > 1)
                    {
                        // diagonal move
                        if((currHeadPositionX != currTail1PositionX) && (currHeadPositionY != currTail1PositionY))
                        {
                            currTail1PositionY--;
                            if (currTail1PositionX > currHeadPositionX) currTail1PositionX--;
                            else if (currTail1PositionX < currHeadPositionX) currTail1PositionX++;
                        }
                        else 
                        {
                            currTail1PositionY--;
                        }
                    }
                    if(abs(currTail1PositionY - currTail2PositionY) > 1)
                    {
                        // diagonal move
                        if((currTail1PositionX != currTail2PositionX) && (currTail1PositionY != currTail2PositionY))
                        {
                            currTail2PositionY--;
                            if (currTail2PositionX > currTail1PositionX) currTail2PositionX--;
                            else if (currTail2PositionX < currTail1PositionX) currTail2PositionX++;
                        }
                        else 
                        {
                            currTail2PositionY--;
                        }
                    }
                    if(abs(currTail2PositionY - currTail3PositionY) > 1)
                    {
                        // diagonal move
                        if((currTail2PositionX != currTail3PositionX) && (currTail2PositionY != currTail3PositionY))
                        {
                            currTail3PositionY--;
                            if (currTail3PositionX > currTail2PositionX) currTail3PositionX--;
                            else if (currTail3PositionX < currTail2PositionX) currTail3PositionX++;
                        }
                        else 
                        {
                            currTail3PositionY--;
                        }
                    }
                    if(abs(currTail3PositionY - currTail4PositionY) > 1)
                    {
                        // diagonal move
                        if((currTail3PositionX != currTail4PositionX) && (currTail3PositionY != currTail4PositionY))
                        {
                            currTail4PositionY--;
                            if (currTail4PositionX > currTail3PositionX) currTail4PositionX--;
                            else if (currTail4PositionX < currTail3PositionX) currTail4PositionX++;
                        }
                        else 
                        {
                            currTail4PositionY--;
                        }
                    }
                    if(abs(currTail4PositionY - currTail5PositionY) > 1)
                    {
                        // diagonal move
                        if((currTail4PositionX != currTail5PositionX) && (currTail4PositionY != currTail5PositionY))
                        {
                            currTail5PositionY--;
                            if (currTail5PositionX > currTail4PositionX) currTail5PositionX--;
                            else if (currTail5PositionX < currTail4PositionX) currTail5PositionX++;
                        }
                        else 
                        {
                            currTail5PositionY--;
                        }
                    }
                    if(abs(currTail5PositionY - currTail6PositionY) > 1)
                    {
                        // diagonal move
                        if((currTail5PositionX != currTail6PositionX) && (currTail5PositionY != currTail6PositionY))
                        {
                            currTail6PositionY--;
                            if (currTail6PositionX > currTail5PositionX) currTail6PositionX--;
                            else if (currTail6PositionX < currTail5PositionX) currTail6PositionX++;
                        }
                        else 
                        {
                            currTail6PositionY--;
                        }
                    }
                    if(abs(currTail6PositionY - currTail7PositionY) > 1)
                    {
                        // diagonal move
                        if((currTail6PositionX != currTail7PositionX) && (currTail6PositionY != currTail7PositionY))
                        {
                            currTail7PositionY--;
                            if (currTail7PositionX > currTail6PositionX) currTail7PositionX--;
                            else if (currTail7PositionX < currTail6PositionX) currTail7PositionX++;
                        }
                        else 
                        {
                            currTail7PositionY--;
                        }
                    }
                    if(abs(currTail7PositionY - currTail8PositionY) > 1)
                    {
                        // diagonal move
                        if((currTail7PositionX != currTail8PositionX) && (currTail7PositionY != currTail8PositionY))
                        {
                            currTail8PositionY--;
                            if (currTail8PositionX > currTail7PositionX) currTail8PositionX--;
                            else if (currTail8PositionX < currTail7PositionX) currTail8PositionX++;
                        }
                        else 
                        {
                            currTail8PositionY--;
                        }
                    }
                    if(abs(currTail7PositionY - currTail8PositionY) > 1)
                    {
                        // diagonal move
                        if((currTail8PositionX != currTail9PositionX) && (currTail8PositionY != currTail9PositionY))
                        {
                            currTail9PositionY--;
                            if (currTail9PositionX > currTail8PositionX) currTail9PositionX--;
                            else if (currTail9PositionX < currTail8PositionX) currTail9PositionX++;
                        }
                        else 
                        {
                            currTail9PositionY--;
                        }
                    }
                    grid[currHeadPositionX][currHeadPositionY] = 'H';
                    grid[currTail1PositionX][currTail1PositionY] = '1';
                    grid[currTail2PositionX][currTail2PositionY] = '2';
                    grid[currTail3PositionX][currTail3PositionY] = '3';
                    grid[currTail4PositionX][currTail4PositionY] = '4';
                    grid[currTail5PositionX][currTail5PositionY] = '5';
                    grid[currTail6PositionX][currTail6PositionY] = '6';
                    grid[currTail7PositionX][currTail7PositionY] = '7';
                    grid[currTail8PositionX][currTail8PositionY] = '8';
                    grid[currTail9PositionX][currTail9PositionY] = '#';
                    // cout << "Current Head Position is : (" << currHeadPositionX << " , " << currHeadPositionY << ")" << endl;
                    // cout << "Current Tail Position is : (" << currTailPositionX << " , " << currTailPositionY << ")" << endl;
                }
            }
            if (myString[0] == 'L')
            {
                for(int l = 0; l < atoi(&myString[2]); l++)
                {
                    currHeadPositionX--;
                    if(abs(currHeadPositionX - currTail1PositionX) > 1)
                    {
                        // diagonal move
                        if((currHeadPositionX != currTail1PositionX) && (currHeadPositionY != currTail1PositionY))
                        {
                            currTail1PositionX--;
                            if (currTail1PositionY > currHeadPositionY) currTail1PositionY--;
                            else if (currTail1PositionY < currHeadPositionY) currTail1PositionY++;
                        }
                        else 
                        {
                            currTail1PositionX--;
                        }
                    }
                    if(abs(currTail1PositionX - currTail2PositionX) > 1)
                    {
                        // diagonal move
                        if((currTail1PositionX != currTail2PositionX) && (currTail1PositionY != currTail2PositionY))
                        {
                            currTail2PositionX--;
                            if (currTail2PositionY > currTail1PositionY) currTail2PositionY--;
                            else if (currTail2PositionY < currTail1PositionY) currTail2PositionY++;
                        }
                        else 
                        {
                            currTail2PositionX--;
                        }
                    }
                    if(abs(currTail2PositionX - currTail3PositionX) > 1)
                    {
                        // diagonal move
                        if((currTail2PositionX != currTail3PositionX) && (currTail2PositionY != currTail3PositionY))
                        {
                            currTail3PositionX--;
                            if (currTail3PositionY > currTail2PositionY) currTail3PositionY--;
                            else if (currTail3PositionY < currTail2PositionY) currTail3PositionY++;
                        }
                        else 
                        {
                            currTail3PositionX--;
                        }
                    }
                    if(abs(currTail3PositionX - currTail4PositionX) > 1)
                    {
                        // diagonal move
                        if((currTail3PositionX != currTail4PositionX) && (currTail3PositionY != currTail4PositionY))
                        {
                            currTail4PositionX--;
                            if (currTail4PositionY > currTail3PositionY) currTail4PositionY--;
                            else if (currTail4PositionY < currTail3PositionY) currTail4PositionY++;
                        }
                        else 
                        {
                            currTail4PositionX--;
                        }
                    }
                    if(abs(currTail4PositionX - currTail5PositionX) > 1)
                    {
                        // diagonal move
                        if((currTail4PositionX != currTail5PositionX) && (currTail4PositionY != currTail5PositionY))
                        {
                            currTail5PositionX--;
                            if (currTail5PositionY > currTail4PositionY) currTail5PositionY--;
                            else if (currTail5PositionY < currTail4PositionY) currTail5PositionY++;
                        }
                        else 
                        {
                            currTail5PositionX--;
                        }
                    }
                    if(abs(currTail5PositionX - currTail6PositionX) > 1)
                    {
                        // diagonal move
                        if((currTail5PositionX != currTail6PositionX) && (currTail5PositionY != currTail6PositionY))
                        {
                            currTail6PositionX--;
                            if (currTail6PositionY > currTail5PositionY) currTail6PositionY--;
                            else if (currTail6PositionY < currTail5PositionY) currTail6PositionY++;
                        }
                        else 
                        {
                            currTail6PositionX--;
                        }
                    }
                    if(abs(currTail6PositionX - currTail7PositionX) > 1)
                    {
                        // diagonal move
                        if((currTail6PositionX != currTail7PositionX) && (currTail6PositionY != currTail7PositionY))
                        {
                            currTail7PositionX--;
                            if (currTail7PositionY > currTail6PositionY) currTail7PositionY--;
                            else if (currTail7PositionY < currTail6PositionY) currTail7PositionY++;
                        }
                        else 
                        {
                            currTail7PositionX--;
                        }
                    }
                    if(abs(currTail7PositionX - currTail8PositionX) > 1)
                    {
                        // diagonal move
                        if((currTail7PositionX != currTail8PositionX) && (currTail7PositionY != currTail8PositionY))
                        {
                            currTail8PositionX--;
                            if (currTail8PositionY > currTail7PositionY) currTail8PositionY--;
                            else if (currTail8PositionY < currTail7PositionY) currTail8PositionY++;
                        }
                        else 
                        {
                            currTail8PositionX--;
                        }
                    }
                    if(abs(currTail8PositionX - currTail9PositionX) > 1)
                    {
                        // diagonal move
                        if((currTail8PositionX != currTail9PositionX) && (currTail8PositionY != currTail9PositionY))
                        {
                            currTail9PositionX--;
                            if (currTail9PositionY > currTail8PositionY) currTail9PositionY--;
                            else if (currTail9PositionY < currTail8PositionY) currTail9PositionY++;
                        }
                        else 
                        {
                            currTail9PositionX--;
                        }
                    }
                    grid[currHeadPositionX][currHeadPositionY] = 'H';
                    grid[currTail1PositionX][currTail1PositionY] = '1';
                    grid[currTail2PositionX][currTail2PositionY] = '2';
                    grid[currTail3PositionX][currTail3PositionY] = '3';
                    grid[currTail4PositionX][currTail4PositionY] = '4';
                    grid[currTail5PositionX][currTail5PositionY] = '5';
                    grid[currTail6PositionX][currTail6PositionY] = '6';
                    grid[currTail7PositionX][currTail7PositionY] = '7';
                    grid[currTail8PositionX][currTail8PositionY] = '8';
                    grid[currTail9PositionX][currTail9PositionY] = '#';
                    // cout << "Current Head Position is : (" << currHeadPositionX << " , " << currHeadPositionY << ")" << endl;
                    // cout << "Current Tail Position is : (" << currTailPositionX << " , " << currTailPositionY << ")" << endl;
                }
            }
        }
    }
    printGrid(grid);
    return 0;
}