#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int main() 
{
    string buf;
    std::ifstream myFile("input.txt");
    int val = 0, max1 = 0, max2 = 0, max3 = 0;
    if ( myFile.is_open() ) 
    {
        vector <int> constructedInt;
        char mychar, lastchar;
        while (myFile) 
        {
            mychar = myFile.get();         
            if ((mychar!= '\n') && (mychar != '\r') && (((int(mychar) - 48 )>= 0))) constructedInt.emplace_back(int(mychar) - 48);
            if (mychar == '\n') 
            {
                for(int i = 0; i < constructedInt.size(); i++)
                {
                    val += constructedInt[i] * (pow(10,(constructedInt.size()-i-1)));
                }
                constructedInt.clear();
                
            }
            else if ((mychar == '\r' && lastchar == '\n') || mychar == 'EOF')
            {
                if (val > max2)
                {
                    max3 = max2;
                    max2 = val;
                }
                if (val > max1) 
                {
                    max2 = max1;
                    max1 = val;
                }
                val = 0;
            }
            lastchar = mychar;
        }
    }
    cout << endl << "Sum is: " << max1 + max2 + max3;
    return 0;
}