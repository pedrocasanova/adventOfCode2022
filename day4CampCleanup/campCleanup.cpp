#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int main() 
{
    ifstream myFile("input.txt");
    int sum = 0;
    if (myFile.is_open()) 
    {
        char myChar, lastChar;
        int start1 = 0, end1 = 0, start2 = 0, end2 = 0, state = 0;
        while (myFile) 
        {
            myChar = myFile.get();
            if (lastChar == '\n')
            {
                state = 0;
                start1 = atoi(&myChar);
            }
            else if (myChar != '\r' && lastChar == ',')
            {
                state = 1;
                start2 = atoi(&myChar);
            }
            else if (myChar != '\r' && lastChar == '-')
            {
                if(state == 0)
                {
                    end1 = atoi(&myChar);
                }
                else if(state == 1)
                {
                    end2 = atoi(&myChar);
                    cout << "Characters are " << start1 << " --- "<< end1 << " || "<< start2 << " --- "<<  end2 << endl;
                    if (start1 >= start2 && end1 <= end2) sum++;
                    else if (start2 >= start1 && end1 >= end2) sum++;
                }
            }
            lastChar = myChar;
        }
    }
    cout << "Sum is: " << sum;
    return 0;
}