#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows)
    {
        vector<vector<int> > outcome;
        for(int i=1;i<=numRows;++i)
        {
            outcome.push_back(vector<int>());
            outcome.back().push_back(1);
            for(int j=1;j<=i-2;++j)
            {
                outcome[i-1].push_back(outcome[i-2][j-1]+outcome[i-2][j]);
            }
            if(i>1)
                outcome.back().push_back(1);
        }
        return outcome;
    }
};

int main()
{
    return 0;
}