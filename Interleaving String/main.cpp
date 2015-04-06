#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
	{
		if(s1.size()+s2.size()!=s3.size())
			return false;
        vector<vector<bool> > store;
		store.resize(s1.size()+1,vector<bool>(s2.size()+1));
		store[0][0]=true;
		for(int i=1;i<=s2.size();++i)
		{
			if(store[0][i-1]&&s2[i-1]==s3[i-1])
				store[0][i]=true;
			else
				store[0][i]=false;
		}
		for(int i=1;i<=s1.size();++i)
		{
			if(store[i-1][0]&&s1[i-1]==s3[i-1])
				store[i][0]=true;
			else
				store[i][0]=false;
		}
		for(int i=1;i<=s1.size();++i)
			for(int k=1;k<=s2.size();++k)
			{
				if(s3[i+k-1]==s1[i-1]&&store[i-1][k])
				{
					store[i][k]=true;
					continue;
				}
				if(s3[i+k-1]==s2[k-1]&&store[i][k-1])
				{
					store[i][k]=true;
					continue;
				}
				store[i][k]=false;
			}
		return store.back().back();
    }
};

int main()
{
	return 0;
}