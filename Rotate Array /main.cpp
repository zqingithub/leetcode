#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        int size=nums.size();
        k%=size;
        for(int i=0;i<size/2;++i)
        {
            swap(nums[i],nums[size-1-i]);
        }
        for(int i=0;i<k/2;++i)
        {
            swap(nums[i],nums[k-1-i]);
        }
        for(int i=k;i<=(size-1+k)/2;++i)
        {
            swap(nums[i],nums[size-1-i+k]);
        }
    }
};


int main()
{
    int store[]={1,2,3,4,5,6};
    vector<int> nums(store,store+6);
    Solution().rotate(nums,3);
    return 0;
}
