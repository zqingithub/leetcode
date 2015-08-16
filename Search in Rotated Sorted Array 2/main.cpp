#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target)
    {
        int pos=findMaxPos(nums, 0, nums.size()-1);
        if(search(nums, 0, pos, target))
            return true;
        return search(nums, pos+1, nums.size()-1, target);
    }
private:
    int findMaxPos(vector<int>& nums,const int s,const int e)
    {
        if(e-s<2)
            return nums[s]>nums[e]?s:e;
        int mid=(s+e)/2;
        if(nums[mid]>nums[s])
            return findMaxPos(nums, mid, e);
        if(nums[mid]<nums[s])
            return findMaxPos(nums, s, mid-1);
        return findMaxPos(nums, s+1, e);;
    }
    bool search(vector<int> &nums,const int s,const int e,const int target)
    {
        if(s>e)
            return false;
        int mid=(s+e)/2;
        if(nums[mid]==target)
            return true;
        if(nums[mid]>target)
            return search(nums,s,mid-1,target);
        else
            return search(nums, mid+1, e, target);
    }
};

int main()
{
    return 0;
}