#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <deque>

using namespace std;

bool checkCharUniquenessInStr(string testString)
{
    for(int i = 0; i < testString.size()-1; i++)
    {
        for(int j = i + 1; j < testString.size();j++)
        {
            if(testString[i] == testString[j]) return false;
        }
    }
    return true;
}

int main() 
{
    ifstream myFile("input.txt");
    string myString, messageString;
    char signal;
    bool difFlag = true;
    if (myFile.is_open()) 
    {
        getline(myFile, myString);
        for(int index = 0; index < myString.size(); index++)
        {
            messageString = myString.substr(index, 14);
            if (checkCharUniquenessInStr(messageString) == true) 
            {
                cout << "String is " << messageString << endl;
                cout << "Index is " << index << endl;
                break;
            }
            messageString.clear();
        }
    }
    return 0;
}