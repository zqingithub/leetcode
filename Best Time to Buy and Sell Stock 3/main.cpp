#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) 
	{
		if(prices.empty())
			return 0;
		vector<int> store(prices.size());
		vector<int>::size_type size=prices.size();
		store.back()=0;
		int Max=prices.back();
		for(int i=size-2;i>=0;--i)
		{
			if(prices[i]>Max)
				Max=prices[i];
			if(Max-prices[i]>store[i+1])
				store[i]=Max-prices[i];
			else
				store[i]=store[i+1];
		}
		int Min=prices[0];
		Max=store[0];
		for(vector<int>::size_type i=1;i<size;++i)
		{
			if(prices[i]<Min)
				Min=prices[i];
			if(prices[i]-Min+store[i]>Max)
				Max=prices[i]-Min+store[i];
		}
		return Max;
    }
};

int main()
{
	vector<int> temp(1);
	temp[0]=1;
	Solution().maxProfit(temp);
	return 0;
}