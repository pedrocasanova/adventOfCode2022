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
        char myChar, sameChar;
        string rucksack, compartment2; 
        while (myFile) 
        {
            myChar = myFile.get();
            if (myChar == '\n')
            {
                compartment2.insert(0, &rucksack[(rucksack.length()/2)]);
                rucksack.erase(rucksack.length()/2, rucksack.length()/2);
                for(int i = 0; i < rucksack.length(); i++)
                {
                    if (compartment2.find(rucksack[i]) != string::npos) sameChar = rucksack[i];
                }
                if (isupper(sameChar))
                {
                    sumPriorities += int(sameChar) - 38;
                }
                else
                {
                    sumPriorities += int(sameChar) - 96;
                }
                rucksack.clear();
                compartment2.clear();
            }
            else if (myChar != '\r')
            {
                rucksack.push_back(myChar);
            }
        }
    }
    cout << "Sum of priorities is: " << sumPriorities;
    return 0;
}