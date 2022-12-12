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
    int countUp = 0, countLeft = 0, countDown = 0, countRight = 0, scenicScore = 0, maxScenicScore = 0;
    vector<vector<int>> forest;
    vector<int> treeline;
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
            // cout << endl << "Left trees are ";
            for(int n = j-1; n < forest[0].size() - 1; n--)
            {
                // cout << forest[i][n] << " ";
                if (forest[i][n] < forest[i][j]) countLeft++;
                if (forest[i][n] >= forest[i][j])  
                {
                    countLeft++;
                    break;
                }
            }
            // cout << endl << "Right trees are ";
            for(int n = j+1; n < forest[0].size() - 1; n++)
            {
                // cout << forest[i][n] << " ";
                if (forest[i][n] < forest[i][j])  countRight++;
                if (forest[i][n] >= forest[i][j])  
                {
                    countRight++;
                    break;
                }
            }
            // cout << endl << "Down trees are ";
            for(int l = i+1; l < forest.size()-1; l++)
            {
                // cout << forest[l][j] << " ";
                if (forest[l][j] < forest[i][j]) countDown++;
                if (forest[l][j] >= forest[i][j]) 
                {
                    countDown++;
                    break;
                }
            }
            // cout << endl << "Up trees are ";
            for(int l = i-1; l < forest.size()-1; l--)
            {
                // cout << forest[l][j] << " ";
                if (forest[l][j] < forest[i][j]) countUp++;
                if (forest[l][j] >= forest[i][j]) 
                {
                    countUp++;
                    break;
                }
            }
            // cout << endl << endl;
            // cout << " count Left is : " << countLeft << " count right is " << countRight << " countUp is " << countUp << " countDown is " << countDown << endl;
            scenicScore = countLeft*countRight*countUp*countDown;
            // cout << " scenicScore is : " << scenicScore << " for tree " << forest[i][j] << endl;
            if(scenicScore > maxScenicScore) maxScenicScore = scenicScore;
            countDown = 0;
            countUp = 0;
            countLeft = 0;
            countRight = 0;
        }
    }
    cout << "Maximum scenic score for input forest is: " << maxScenicScore << endl;
    return 0;
}