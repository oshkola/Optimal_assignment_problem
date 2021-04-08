#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void optimalAssignments(string strArr[], int arrLength)
{
    vector<vector<int> > mixedMatrix(arrLength);
    char comma = ',', lbracket = '(', rbracket = ')';
    
    for(int x = 0; x < arrLength; x++)
    {
        strArr[x].erase(remove(strArr[x].begin(), strArr[x].end(), '('), strArr[x].end());
        strArr[x].erase(remove(strArr[x].begin(), strArr[x].end(), ')'), strArr[x].end());
    }
    vector<vector<int> > tmp(arrLength);

    for(int x = 0; x < arrLength; x++)
    {
        int i;
        stringstream s(strArr[x]);
        while(s >> i)
        {
            tmp[x].push_back(i);
            if(s.peek() == ',')
                s.ignore();
        }
    }

    for(int x = 0; x < arrLength; x++)
    {
        for(int i = 0; i < tmp[x].size(); i++)
        {
            mixedMatrix[x].push_back(tmp[i][x]);
        }
    }

    vector<int> minCostIndex;
    for(int i = 0; i < mixedMatrix.size(); i++)
    {
        int minIndex = min_element(mixedMatrix[i].begin(), mixedMatrix[i].end()) - mixedMatrix[i].begin() + 1;
        
        for(auto x: minCostIndex)
        {
            if(x == minIndex)
            {
                mixedMatrix[i][minIndex - 1] = 10000;
                minIndex = min_element(mixedMatrix[i].begin(), mixedMatrix[i].end()) - mixedMatrix[i].begin() + 1;
            }
        }
        minCostIndex.push_back(minIndex);
    }
    for(int i = 1; i <= minCostIndex.size(); i++)
        cout << "(" << i << "-" << minCostIndex[i - 1] << ")";
}

int main()
{
  string A[] = {"(1,2,1)", "(4,1,5)", "(5,2,1)"};
  int arrLength = sizeof(A) / sizeof(*A);
  optimalAssignments(A, arrLength);
}
