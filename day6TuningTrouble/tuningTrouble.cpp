#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <deque>

using namespace std;

int main() 
{
    ifstream myFile("input.txt");
    string myString;
    char signal;
    if (myFile.is_open()) 
    {
        while(myFile)
        {
            getline(myFile, myString);
            for(int index = 0; index < myString.size(); index++)
            {
                if (myString[index] != myString[index+1]
                && myString[index] != myString[index+2]
                && myString[index] != myString[index+3]
                && myString[index+1] != myString[index+3] 
                && myString[index+1] != myString[index+2] 
                && myString[index+2] != myString[index+3])
                {
                    cout << "char0: " << myString[index] << " char1: " << myString[index+1] << 
                            " char2: " << myString[index+2] << " char3: " << myString[index+3] << endl;
                    cout << "index is :: " << index+4;
                    break;
                }
            }
        }    
    }
    return 0;
}