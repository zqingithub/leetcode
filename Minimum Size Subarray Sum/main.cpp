#include<vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    	int S=0,E=0,min,size=nums.size(),sum=0;
    	min=size+1;
    	if(size==0)
    		return 0;
    	if(s==0)
    		return 1;
    	while(E<size)
    	{
    		while(E<size&&sum<s) sum+=nums[E++];
    		if(sum>=s)
    		{
        		while(sum>=s) sum-=nums[S++];
        		if(E-S+1<min)
        			min=E-S+1;
    		}
    	}
    	return min==size+1?0:min;
    }
};

int main()
{
	return 0;
}

