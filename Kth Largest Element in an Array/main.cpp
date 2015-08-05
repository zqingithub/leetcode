#include<iostream>
#include<vector>
#include <cstdlib>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return recFind(nums, k, 0, nums.size()-1);
    }
private:
    int recFind(vector<int>& nums,const int k,const int s,const int e)
    {
        if(s==e)
            return nums[s];
        int index=nums[rand()%(e-s+1)+s];
        int l=s,r=e,mid;
        while(l<r)
        {
            while(l<r&&nums[l]>index)++l;
            while(r>l&&nums[r]<=index)--r;
            swap(nums[l],nums[r]);
        }
        if(nums[l]<=index)
            --l;
        mid=l+1;
        r=e;
        while(mid<r)
        {
            while(mid<r&&nums[mid]==index)++mid;
            while(mid<r&&nums[r]!=index)--r;
            swap(nums[mid], nums[r]);
        }
        if(nums[mid]!=index)
            --mid;
        if(k+s-1<=l)
            return recFind(nums, k, s, l);
        else
        {
            if(k+s-1<=mid)
                return index;
            else
                return recFind(nums, k-(mid-s+1), mid+1, e);
        }
    }
};

int main()
{
    int temp[]={-1,2,0};
    vector<int> tempv(temp,temp+3);
    Solution temps;
    int a=temps.findKthLargest(tempv, 2);
    return 0;
}
