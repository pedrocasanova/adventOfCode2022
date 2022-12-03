#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int main() 
{
    ifstream myFile("input.txt");
    int sumPriorities = 0;
    if (myFile.is_open()) 
    {
        int i = 0;
        char myChar, sameChar;
        string tempRucksack, rucksack1, rucksack2, rucksack3; 
        while (myFile) 
        {
            myChar = myFile.get();
            if (myChar == '\n')
            {
                i++;
                if(i == 1) rucksack1 = tempRucksack;
                else if (i == 2) rucksack2 = tempRucksack;
                if (i == 3)
                {
                    rucksack3 = tempRucksack;
                    for(int i = 0; i < rucksack1.length(); i++)
                    {
                        if (rucksack2.find(rucksack1[i]) != string::npos)
                        {
                            if(rucksack3.find(rucksack1[i]) != string::npos) sameChar = rucksack1[i];
                            cout << sameChar;
                        }
                    }
                    if (isupper(sameChar))
                    {
                        sumPriorities += int(sameChar) - 38;
                    }
                    else
                    {
                        sumPriorities += int(sameChar) - 96;
                    }
                    rucksack1.clear();
                    rucksack2.clear();
                    rucksack3.clear();
                    i = 0;
                }
                tempRucksack.clear();
            }
            else if (myChar != '\r')
            {
                tempRucksack.push_back(myChar);
            }
        }
    }
    cout << "Sum of priorities is: " << sumPriorities;
    return 0;
}