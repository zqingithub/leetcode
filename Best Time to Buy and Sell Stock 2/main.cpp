#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) 
	{
		if(prices.empty())
			return 0;
        int sum=0;
		int index=prices[0];
		vector<int>::size_type size=prices.size();
		for(vector<int>::size_type i=1;i<size;++i)
		{
			if(prices[i]<prices[i-1])
			{
				sum+=prices[i-1]-index;
				index=prices[i];
			}
		}
		sum+=prices.back()-index;
		return sum;
    }
};

int main()
{
	return 0;
}