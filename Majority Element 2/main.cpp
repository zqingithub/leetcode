#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        vector<int> outcome;
        int count[2]={0,0};
        int store[2]={0,0};
        int temp;
        for(vector<int>::size_type i=0;i<nums.size();++i)
        {
            temp=nums[i];
            if(temp==store[0]||temp==store[1])
            {
                ++count[temp==store[0]?0:1];
            }
            else
            {
                bool sign=true;
                for(int j=0;j<2;++j)
                {
                    if(count[j]<=0)
                    {
                        count[j]=1;
                        store[j]=temp;
                        sign=false;
                        break;
                    }
                }
                if(sign)
                {
                    --count[0];
                    --count[1];
                }
            }
        }
        count[0]=count[1]=0;
        for(vector<int>::size_type i=0;i<nums.size();++i)
        {
            if(nums[i]==store[0]) ++count[0];
            if(nums[i]==store[1]) ++count[1];
        }
        if(count[0]>nums.size()/3) outcome.push_back(store[0]);
        if(count[1]>nums.size()/3&&store[0]!=store[1]) outcome.push_back(store[1]);
        return outcome;
    }
};

int main()
{
    return 0;
}
