#include<iostream>
#include<set>
#include<vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    	set<int> isHave;
    	if(nums.size()==0)
    		return false;
    	for(int i=nums.size()-1;i>=0;--i)
    	{
    		if(isHave.find(nums[i])!=isHave.end())
    			return true;
    		else
    			isHave.insert(nums[i]);
    	}
    	return false;
    }
};
int main()
{
	vector<int> temp;
	temp.push_back(0);
	Solution().containsDuplicate(temp);
	return 0;
}



