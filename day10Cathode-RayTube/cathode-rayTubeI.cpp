#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>

using namespace std;

int main()
{
    ifstream myFile("input.txt");
    string myString, token;
    int cycleCount = 0, registerX = 1, registerAdder = 0;
    long int signalStrength = 0, signalStrengthSum = 0;
    if (myFile.is_open()) 
    {
        while(myFile)
        {
            getline(myFile, myString);
            cout << myString << endl;
            // noop instruction
            if(myString[0] == 'n') cycleCount++;
            if (cycleCount == 20 || cycleCount == 60 || cycleCount == 100 || cycleCount == 140 || cycleCount == 180 || cycleCount == 220)
            {
                signalStrength = cycleCount * registerX;
                signalStrengthSum = signalStrengthSum + signalStrength;
            }
            // add instruction
            else if(myString[0] == 'a')
            {
                // parse out
                token =  myString.substr(myString.find(' '), myString.find('\r') - myString.find(' '));
                registerAdder = stoi(token);
                
                cycleCount++;
                if (cycleCount == 20 || cycleCount == 60 || cycleCount == 100 || cycleCount == 140 || cycleCount == 180 || cycleCount == 220)
                {
                    signalStrength = cycleCount * registerX;
                    signalStrengthSum = signalStrengthSum + signalStrength;
                }
                // only at the end of the two cycle counts do we add to register X
                cycleCount++;
                if (cycleCount == 20 || cycleCount == 60 || cycleCount == 100 || cycleCount == 140 || cycleCount == 180 || cycleCount == 220)
                {
                    signalStrength = cycleCount * registerX;
                    signalStrengthSum = signalStrengthSum + signalStrength;
                }
                registerX = registerX + registerAdder;
            }
        }
    }
    cout << "signalStrengthSum is " << signalStrengthSum << endl;
    return 0;
}