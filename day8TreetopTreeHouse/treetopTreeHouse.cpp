#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>

using namespace std;

void printForest(vector<vector<int>> sampleForest)
{
    for(int i = 0; i < sampleForest.size()-1; i++)
    {
        for (int j = 0; j < sampleForest[0].size() - 1; j++)
        {
            cout << sampleForest[i][j];
        }
        cout << endl;
    }
}

int main() 
{
    ifstream myFile("input.txt");
    string myString;
    char tree;
    int visibleTreeCount = 0;
    vector<vector<int>> forest;
    vector<int> treeline;
    bool isVisible = true, isVisibleFromLeft = true, isVisibleFromUp = true, isVisibleFromDown = true, isVisibleFromRight = true;
    if (myFile.is_open()) 
    {
        while(myFile)
        {
            getline(myFile, myString);
            for(int i = 0; i < myString.size(); i++)
            {
                if (myString[i] != '\r' || myString[i] != '\n')
                {
                    tree = myString[i];
                    treeline.emplace_back((int)tree - '0');
                }
            }
            forest.emplace_back(treeline);
            treeline.clear();
        }
    }
    for(int i = 0; i < forest.size()-1; i++)
    {
        for (int j = 0; j < forest[0].size() - 1; j++)
        {
            // cout << "i: " << i << " j " << j << " val " << forest[i][j] << endl;
            if(i == 0) visibleTreeCount ++;
            else if (j == 0) visibleTreeCount++;
            else if (i == forest[0].size()-2) visibleTreeCount++;
            else if (j == forest[0].size()-2) visibleTreeCount++;
            else
            {
                // cout << endl << "Left trees are ";
                for(int n = j-1; n < forest[0].size() - 1; n--)
                {
                //     cout << forest[i][n] << " ";
                    if (forest[i][n] >= forest[i][j]) isVisibleFromLeft = false;
                }
                // cout << endl << "Right trees are ";
                for(int n = j+1; n < forest[0].size() - 1; n++)
                {
                //   cout << forest[i][n] << " ";
                    if (forest[i][n] >= forest[i][j]) isVisibleFromRight = false;
                }
                // cout << endl << "Down trees are ";
                for(int l = i+1; l < forest.size()-1; l++)
                {
                //    cout << forest[l][j] << " ";
                    if (forest[l][j] >= forest[i][j]) isVisibleFromDown = false;
                }
                // cout << endl << "Up trees are ";
                for(int l = i-1; l < forest.size()-1; l--)
                {
                //    cout << forest[l][j] << " ";
                    if (forest[l][j] >= forest[i][j]) isVisibleFromUp = false;
                }
                // cout << endl << endl;
                isVisible = isVisibleFromUp || isVisibleFromDown || isVisibleFromLeft || isVisibleFromRight;
                if (isVisible == true) 
                {
                //    cout << "This tree is visible: " << forest[i][j] << endl;
                    visibleTreeCount++;   
                }
                isVisibleFromLeft = true;
                isVisibleFromRight = true;
                isVisibleFromDown = true;
                isVisibleFromUp = true;
            }
        }
    }
    cout << "Amount of visible trees is: " << visibleTreeCount << endl;
    return 0;
}