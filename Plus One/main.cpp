#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        vector<int> outcome(digits.size()+1,0);
        outcome[digits.size()]=1;
        for(int i=digits.size()-1;i>=0;--i)
        {
            outcome[i]+=(outcome[i+1]+digits[i])/10;
            outcome[i+1]=(outcome[i+1]+digits[i])%10;
        }
        if(outcome[0]==0)
            outcome.erase(outcome.begin(),outcome.begin()+1);
        return outcome;
    }
};

int main()
{
    Solution temp;
    vector<int> nums(1,9);
    temp.plusOne(nums);
    return 0;
}