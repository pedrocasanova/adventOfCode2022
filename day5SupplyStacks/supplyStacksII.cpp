#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <deque>

using namespace std;

void printOut(vector<deque<char>> object)
{
    for(int i = 0; i < object.size(); i ++)
    {
        cout << "COLUMN " << i+1 << " :" << endl;
        while(object[i].size() != 0)
        {
            cout << object[i].front() << endl;
            object[i].pop_front();
        }
    }
}

int main() 
{
    ifstream myFile("input.txt");
    string myString, token;
    int state = 0, numColumns = 0, index = 0, index2 = 0, amount = 0, from = 0, to = 0;
    char move;
    vector<deque<char>> supplyStack;
    deque<char> stack;
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
                    if(myString[(i*4)+1] != ' ') supplyStack[i].push_back(myString[(i*4)+1]);
                }
            }
            else if(state == 2 && ((myString[0] == 'm')))
            {
                index = myString.find(" from");
                token = myString.substr(5, index);
                amount = stoi(token);
                index2 = myString.find(" to");
                token = myString.substr(index+5, index2);
                from = stoi(token);
                index = myString.find('\r');
                token = myString.substr(index2+4, index);
                to = stoi(token);
                for(int i = 0; i < amount; i++)
                {
                    stack.emplace_front(supplyStack[from-1].front()); 
                    supplyStack[from-1].pop_front();
                }
                for(int i = 0; i < amount; i++)
                {
                    move = stack.front();
                    stack.pop_front();
                    supplyStack[to-1].emplace_front(move);
                }
            }
        }
        printOut(supplyStack);
    }
    return 0;
}