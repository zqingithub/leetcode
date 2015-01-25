#include<iostream>
using namespace std;
class Solution {
public:
    int jump(int A[], int n) 
	{
		int times=0;
		int maxGet=0;
		int maxTo=A[0];
		for(int i=1;i<n;++i)
		{
			if(i>maxGet)
			{
				++times;
				maxGet=maxTo;
			}
			if(A[i]+i>maxTo)
				maxTo=A[i]+i;
		}
		return times;
    }
};
int main()
{
	return 0;
}