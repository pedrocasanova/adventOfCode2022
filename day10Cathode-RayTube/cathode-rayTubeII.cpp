#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>

using namespace std;

void  initCrt(char sampleCrt[6][40])
{
    char testChar = '.';
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 40; j++)
        {
            sampleCrt[i][j] = testChar;
        }
    }
}

void  printCrt(char sampleCrt[6][40])
{
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 40; j++)
        {
            cout << "\033[1;32m" << sampleCrt[i][j] << "\033[0m";
        }
        cout << endl;
    }
}

int main()
{
    ifstream myFile("input.txt");
    string myString, token;
    int cycleCount = 0, registerX = 1, registerAdder = 0;
    int crtX = 0, crtY = 0;
    long int signalStrength = 0, signalStrengthSum = 0;
    char crtScreen[6][40];
    initCrt(crtScreen);
    printCrt(crtScreen);
    if (myFile.is_open()) 
    {
        while(myFile)
        {
            getline(myFile, myString);
            // noop instruction
            if(myString[0] == 'n') 
            {
                cycleCount++;
                if(cycleCount == 40 || cycleCount == 80 || cycleCount == 120 || cycleCount == 160 || cycleCount == 200 || cycleCount == 240)
                {
                    crtY++;
                    crtX = 0;
                }
                else 
                {
                    crtX++;
                }
                if((registerX - 1 == crtX) || (registerX == crtX) || (registerX + 1 == crtX))  crtScreen[crtY][crtX] = '#';
                cout << "cycle count :" << cycleCount << " crtX :: " << crtX << " crtY :: " << crtY << endl;
            }
            // add instruction
            else if(myString[0] == 'a')
            {
                // parse out
                token =  myString.substr(myString.find(' '), myString.find('\r') - myString.find(' '));
                registerAdder = stoi(token);
                cycleCount++;
                if(cycleCount == 40 || cycleCount == 80 || cycleCount == 120 || cycleCount == 160 || cycleCount == 200 || cycleCount == 240)
                {
                    crtY++;
                    crtX = 0;
                }
                else 
                {
                    crtX++;
                }
                if((registerX - 1 == crtX) || (registerX == crtX) || (registerX + 1 == crtX))  crtScreen[crtY][crtX] = '#';
                cout << "cycle count :" << cycleCount << " crtX :: " << crtX << " crtY :: " << crtY << endl;
                // only at the end of the two cycle counts do we add to register X
                cycleCount++;
                registerX = registerX + registerAdder;
                if(cycleCount == 40 || cycleCount == 80 || cycleCount == 120 || cycleCount == 160 || cycleCount == 200 || cycleCount == 240)
                {
                    crtY++;
                    crtX = 0;
                }
                else 
                {
                    crtX++;
                }
                if((registerX - 1 == crtX) || (registerX == crtX) || (registerX + 1 == crtX))  crtScreen[crtY][crtX] = '#';
                cout << "cycle count :" << cycleCount << " crtX :: " << crtX << " crtY :: " << crtY << endl;
            }
        }
    }
    printCrt(crtScreen);
    return 0;
}