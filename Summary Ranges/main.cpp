#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> outcome;
        if(nums.size()==0)
            return outcome;
        int s=nums[0],e=nums[0];
        nums.push_back(nums.back()+2);
        for(vector<int>::size_type i=1;i<nums.size();++i)
        {
            if(nums[i]==e+1)
                ++e;
            else
            {
                if(s!=e)
                    outcome.push_back(to_string(s)+"->"+to_string(e));
                else
                    outcome.push_back(to_string(s));
                s=e=nums[i];
            }
        }
        
        return outcome;
    }
};

int main()
{
    return 0;
}
