#include<iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n)
    {
    	if(0==n)
    		return 0;
    	int index=A[0];
    	int times=1;
    	int sum=1;
    	for(int i=1;i<n;++i)
    	{
    		if(A[i]==index)
    		{
    			if(times<2)
    			{
    	   			++times;
    			}
    			else
    				continue;

    		}
    		else
    		{
    			index=A[i];
    			times=1;
    		}
    		A[sum]=A[i];
    		++sum;

    	}
    	return sum;
    }
};

int main()
{
	return 0;
}




