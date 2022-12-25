#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <queue>

using namespace std;
class monkey
{
    public:
        // number of inspections
        int falseMonkey;
        // queue of items, represented by their base worry level
        vector<long int> items;
        // type of operation performed on worry level upon inspection
        char operationType;
        // operator to use on worry level upon inspection
        int operatorNumber;
        // number by which which worry level should be divisible
        int test;
        // monkey to whom item will be tossed in case test passes
        int trueMonkey;
        //
        int numberInspections;
    private: 

};

int main()
{
    monkey monke;
    vector<monkey> troop;
    ifstream myFile("input.txt");
    string myString, token;
    int monkeyIndex = 0;
    if (myFile.is_open()) 
    {
        while(myFile)
        {
            getline(myFile, myString);
            if(myString[0] == 'M')
            {
                monkeyIndex = atoi(&myString[7]);
                troop.insert(troop.begin() + monkeyIndex, monke);
                troop[monkeyIndex].numberInspections = 0;
            }
            else if(myString[2] == 'S')
            {
                token = myString.substr(18, myString.find('\r'));
                while(token.size() > 2)
                {
                    int item = stoi(token.substr(0, token.find(',')));
                    troop[monkeyIndex].items.emplace_back(item);
                    token = token.substr(token.find(', ')+1, token.find('\r'));
                    // cout << "Emplaced item " << item << endl;
                }
            }
            else if(myString[2] == 'O')
            {
                troop[monkeyIndex].operationType = myString[23];
                if (myString[25] == 'o') troop[monkeyIndex].operatorNumber = 0;
                else
                {
                    troop[monkeyIndex].operatorNumber = stoi(myString.substr(myString.rfind(' '), myString.find('\r')));
                }
            }
            else if(myString[2] == 'T')
            {
                troop[monkeyIndex].test = stoi(myString.substr(myString.rfind(' '), myString.find('\r')));
            }
            else if(myString[8] == 'r')
            {
                troop[monkeyIndex].trueMonkey = stoi(myString.substr(myString.rfind(' '), myString.find('\r')));
            }
            else if(myString[7] == 'f')
            {
                troop[monkeyIndex].falseMonkey = stoi(myString.substr(myString.rfind(' '), myString.find('\r')));
            }
        }
    }
    // printout troop
    // for(int i = 0; i < troop.size(); i++)
    // {
    //     cout << "Monkey " << i << " has items: " << endl;
    //     for(int j = 0; j < troop[i].items.size(); j++)
    //     {
    //         cout << troop[i].items[j] << ",";
    //     }
    //     cout << endl << "It's operation type is " << troop[i].operationType << endl; 
    //     cout << "It's operator number is " << troop[i].operatorNumber << endl;
    //     cout << "It's test is: Divisible by " << troop[i].test << endl;
    //     cout << "It's trueMonkey is: " << troop[i].trueMonkey << endl;
    //     cout << "It's falseMonkey is: " << troop[i].falseMonkey << endl;
    //     cout << endl;
    // }
    long int worryLevel = 0;
    // simulate 10000 rounds
    for(int i = 0; i < 10000; i++)
    {
        // each jth monkey
        for(int j = 0; j < troop.size(); j++)
        {
            // inspects each item
            for(int k = 0; k < troop[j].items.size(); k++)
            {
                worryLevel = troop[j].items[k];
                // cout << "Monkey " << j << " inspects an item with worry level " << worryLevel << endl;
                if(troop[j].operationType == '*')
                {
                    if (troop[j].operatorNumber == 0)
                    {
                        worryLevel = worryLevel * worryLevel;
                    }
                    else worryLevel = worryLevel * troop[j].operatorNumber;
                }
                else if(troop[j].operationType == '+')
                {
                    if (troop[j].operatorNumber == 0)
                    {
                        worryLevel = worryLevel + worryLevel;
                    }
                    else worryLevel = worryLevel + troop[j].operatorNumber;
                }
                // cout << "New worry level is " << worryLevel << endl;
                // divide by common denominator to prevent overflow
                worryLevel = worryLevel%(9699690);
                // cout << "Monkey gets bored with item. New worry level is " << worryLevel << endl;
                if((worryLevel % (troop[j].test)) == 0)
                {
                    // cout << "Item with worry level " << worryLevel << " is tossed to monkey " << troop[j].trueMonkey << "." << endl;
                    troop[troop[j].trueMonkey].items.emplace_back(worryLevel);
                }
                else 
                {
                    // cout << "Item with worry level " << worryLevel << " is tossed to monkey " << troop[j].falseMonkey << "." << endl;
                    troop[troop[j].falseMonkey].items.emplace_back(worryLevel);
                }
                troop[j].numberInspections++;
            }
            troop[j].items.clear();
        }
        // cout << "End of round balance " << endl;
        for(int i = 0; i < troop.size(); i++)
        {
            // cout << "Monkey " << i << " has items: " << endl;
            for(int j = 0; j < troop[i].items.size(); j++)
            {
                // cout << troop[i].items[j] << ",";
            }
            // cout << endl;
        }
    }
    cout << endl << "NUMBER OF INSPECTIONS " << endl;
    for(int l = 0; l < troop.size(); l++)
    {
        cout << troop[l].numberInspections << endl;
    }
    return 0;
}