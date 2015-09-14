#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
	{
		int temp=0;
		int count=0;
		for(int i=0;i<nums.size();++i)
		{
			temp^=nums[i];
			if(nums[i]==0)++count;
		}
		if(count==1)
		{
			vector<int> outcome;
			outcome.push_back(0);
			outcome.push_back(temp);
			return outcome;
		}
        return rec(0,nums.size()-1,nums);
    }
	vector<int> rec(const int s,const int e,vector<int> &nums)
	{
		vector<int> outcome;
		if(e-s==1)
		{
			outcome.push_back(nums[s]);
			outcome.push_back(nums[e]);
			return outcome;
		}
		int index=s;
		while(index==s)index=part(s,e,nums[s+rand()%(e-s+1)],nums);
		int temp1=0,temp2=0;
		for(int i=s;i<index;++i)
		{
			temp1^=nums[i];
		}
		for(int i=index;i<=e;++i)
		{
			temp2^=nums[i];
		}
		if(temp1!=0&&temp2!=0)
		{
			outcome.push_back(temp1);
			outcome.push_back(temp2);
			return outcome;
		}
		if(temp1!=0)
			return rec(s,index-1,nums);
		else
			return rec(index,e,nums);

	}
	int part(const int s,const int e,const int index,vector<int> &nums)
	{
		int l=s,r=e;
		while(l<r)
		{
			while(l<r&&nums[l]<index)++l;
			while(l<r&&nums[r]>=index)--r;
			swap(nums[l],nums[r]);
		}
		if(nums[l]>=index)
			return l;
		else
			return l+1;
	}
};

int main()
{
	int store[]={1,2,1,3,5,2};
	vector<int> v(store,store+6);
	vector<int> outcome=Solution().singleNumber(v);
	return 0;
}