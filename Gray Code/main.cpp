#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) 
	{
		vector<int> out;
		out.push_back(0);
		if(0==n)
			return out;
		out.push_back(1);
		for(int i=1;i<n;++i)
		{
			int temp=out.size();
			int one=1<<i;
			for(int k=temp-1;0<=k;--k)
			{
				out.push_back(out[k]|one);
			}
		}
		return out;
    }
};

int main()
{
	return 0;
}