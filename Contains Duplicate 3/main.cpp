#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long> store;
        multiset<long long>::iterator itr;
        for(int i=0;i<nums.size();++i)
        {
            if(store.size()>k)
            {
                store.erase(store.find(nums[i-(k+1)]));
            }
            itr=store.lower_bound(nums[i]-t);
            if(itr!=store.end()&&abs(*itr-nums[i])<=t)
                return true;
            store.insert(nums[i]);
        }
        return false;
    }
};

int main()
{
    return 0;
}
