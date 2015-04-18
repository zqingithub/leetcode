#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
    	if(0==prices.size())
    		return 0;
    	int min=prices[0];
    	int max=0;
    	int size=prices.size();
    	for(int i=0;i<size;++i)
    	{
    		if(prices[i]<min)
    			min=prices[i];
    		if(prices[i]-min>max)
    			max=prices[i]-min;
    	}
    	return max;
    }
};

int main()
{
	return 0;
}



