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
    string myString, token;
    int state = 0, numColumns = 0, index = 0, amount = 0;
    vector<deque<int>> supplyStack;
    deque<int> stack;
    if (myFile.is_open()) 
    {
        while(myFile)
        {
            getline(myFile, myString);
            if (state == 0)
            {
                numColumns = myString.size()/4;
                for (int i = 0; i < numColumns; i++) supplyStack.push_back(stack);
                cout << "supply Stack " << supplyStack.size() << endl;
                state++;
            }
            else if (myString[1] == '1')
            {
                state = 2;
                cout << "now taking orders " << endl;
            }
            else if (state == 1)
            {
                for(int i = 0; i < numColumns; i++)
                {
                    if(myString[(i*4)+1] != ' ') supplyStack[0].push_back(myString[(i*4)+1]);
                }
            }
            else if(state == 2 && myString[0] != '\r')
            {
                index = myString.find(" from");
                for(int i = 5; i < index; i++) token.push_back(myString[i]);
                for(int i = 0; i < token.size()-1; i++)
                {
                    amount += atoi(&token[i]) * pow(10, token.size()-i-1);
                }
                cout << " amount " << amount << endl;
                token.clear();
                amount = 0;
                index = myString.find(" to");
                cout << index << endl;
                index = myString.find('\r');
                cout << index << endl;
                cout << "NEW ONE " << endl;
            }
        }
    }
    return 0;
}