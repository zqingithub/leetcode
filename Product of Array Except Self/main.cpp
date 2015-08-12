#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> outcome(nums.size(),0);
        int size=nums.size();
        outcome[0]=nums[0];
        for(int i=1;i<size;++i)
        {
            outcome[i]=nums[i]*outcome[i-1];
        }
        int temp=1;
        for(int i=size-1;i>0;--i)
        {
            outcome[i]=outcome[i-1]*temp;
            temp*=nums[i];
        }
        outcome[0]=temp;
        return outcome;
    }
};

int main()
{
    return 0;
}
