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
    int val = 0, max = 0;
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
                cout << "NEW CAL::" << endl;
                for(int i = 0; i < constructedInt.size(); i++)
                {
                    cout << " constructedInt[i] * (10^i) " << constructedInt[i] * pow(10,(constructedInt.size()-i-1)) << endl;
                    val += constructedInt[i] * (pow(10,(constructedInt.size()-i-1)));
                }
                cout << "END LOOP" << endl;
                cout << "val:: " << val << endl;
                constructedInt.clear();
                
            }
            else if ((mychar == '\r' && lastchar == '\n') || mychar == 'EOF')
            {
                cout << "NEW ELF " << endl;
                if (val > max) 
                {
                    max = val;
                    cout << "::::::::::::::NEW MAX::::::::::" << max << endl;
                }
                val = 0;
            }
            lastchar = mychar;
        }
    }
    cout << endl << "Maximum is: " << max;
    return 0;
}