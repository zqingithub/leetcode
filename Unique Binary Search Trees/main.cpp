#include<iostream>
using namespace std;

class Solution {
public:
    int numTrees(int n) 
	{
		int * store=new int[n+1];
		store[0]=1;
		for(int i=1;i<n+1;++i)
		{
			store[i]=0;
			for(int k=0;k<i;++k)
			{
				store[i]+=store[k]*store[i-1-k];
			}
		}
		int temp=store[n];
		delete [] store;
		return temp;
    }
};

int main()
{
	return 0;
}