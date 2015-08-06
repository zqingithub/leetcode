#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size=nums.size();
        map<int, int> store;
        map<int,int>::iterator ite;
        for(int i=0;i<size;++i)
        {
            ite=store.find(nums[i]);
            if(ite!=store.end())
            {
                if(i-ite->second<=k)
                    return true;
            }
            store[nums[i]]=i;
        }
        return false;
    }
};

int main()
{
    return 0;
}
