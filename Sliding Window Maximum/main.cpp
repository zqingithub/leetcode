#include<iostream>
#include<deque>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> outcome;
        deque<int> storeMax;
        for(vector<int>::size_type i=0;i<nums.size();++i)
        {
            if(!storeMax.empty()&&storeMax.front()==i-k) storeMax.pop_front();
            while(!storeMax.empty()&&nums[storeMax.back()]<nums[i]) storeMax.pop_back();
            storeMax.push_back(i);
            if(i>=k-1)
                outcome.push_back(nums[storeMax.front()]);
        }
        return outcome;
    }
};

int main()
{
    return 0;
}