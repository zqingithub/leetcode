#include<iostream>
using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) 
	{
		int *create=new int[(S.size()+1)*(T.size()+1)];
		int **store=new int*[S.size()+1];
		int size_S=S.size()+1;
		int size_T=T.size()+1;
		for(int i=0;i<size_S;++i)
		{
			store[i]=&create[i*size_T];
			store[i][0]=1;
		}
		for(int i=1;i<size_T;++i)
			store[0][i]=0;
		for(int i=1;i<size_S;++i)
			for(int k=1;k<size_T;++k)
			{
				store[i][k]=0;
				if(T[k-1]==S[i-1])
					store[i][k]+=store[i-1][k-1];
				store[i][k]+=store[i-1][k];
			}
		int temp=store[size_S-1][size_T-1];
		delete [] create;
		delete [] store;
		return temp;
    }
};

int main()
{
	return 0;
}