#include<iostream>
#include<string>
using namespace std;

typedef long long LL;

class Solution {
public:
    int numDecodings(string s) 
	{
		if(0==s.size())
			return 0;
		LL * store=new LL[s.size()+1];
		store[0]=1;
		for(int i=0;i<s.size();++i)
		{
			store[i+1]='0'==s[i]?0:store[i];
			if(0<=i-1)
			{
				int temp=s[i]-'0'+(s[i-1]-'0')*10;
				if(10<=temp&&26>=temp)
					store[i+1]+=store[i-1];
			}
		}
		LL out=store[s.size()];
		delete[] store;
		return out;
    }
};

int main()
{
	return 0;
}