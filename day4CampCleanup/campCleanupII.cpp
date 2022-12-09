#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int main() 
{
    ifstream myFile("input.txt");
    string myString, subStr;
    int sum = 0;
    if (myFile.is_open()) 
    {
        char myChar, lastChar;
        int indexStart1 = 0, indexEnd1 = 0, indexStart2 = 0, indexEnd2 = 0;
        int start1 = 0, end1 = 0, start2 = 0, end2 = 0;
        while (myFile) 
        {
            getline(myFile, myString);
            indexStart1 = myString.find('-');
            if (indexStart1 != -1) 
            {
                subStr = myString.substr(0, indexStart1);
                start1 = stoi(subStr);
            }
            indexEnd1 = myString.find(',');
            if (indexEnd1 != -1) 
            {
                subStr = myString.substr(indexStart1+1, indexEnd1);
                end1 = stoi(subStr);
            }
            indexStart2 = myString.rfind('-');
            if (indexStart2 != -1) 
            {
                subStr = myString.substr(indexEnd1+1, indexStart2);
                start2 = stoi(subStr);
            }
            indexEnd2 = myString.find('\r');
            if (indexEnd2 != -1) 
            {
                subStr = myString.substr(indexStart2+1, indexEnd2);
                end2 = stoi(subStr);
                if (end2 < start1 || end1 < start2) {} 
                else sum++;
            }
        }
    }
    cout << "Sum is: " << sum;
    return 0;
}