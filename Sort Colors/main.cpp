#include<iostream>
using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
    	int store[3];
    	store[0]=store[1]=store[2]=0;
    	for(int i=0;i<n;++i)
    		++store[A[i]];
    	int index=0;
    	for(int i=0;i<3;++i)
    		while(store[i]-->0)
    			A[index++]=i;

    }
};

int main()
{
	return 0;
}




