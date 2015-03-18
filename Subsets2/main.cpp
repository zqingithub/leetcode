#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) 
	{
        sort(S.begin(),S.end());
		int index=0;
		vector<vector<int> >out;
		out.push_back(vector<int>());
		for(int i=0;i<S.size();++i)
		{
			if(i>0&&S[i]==S[i-1])
				++index;
			else
				index=0;
			int s_out=out.size();
			for(int k=0;k<s_out;++k)
			{
				int temp=out[k].size()-1;
				while(temp>=0&&S[i]==out[k][temp]) --temp;
				temp=out[k].size()-1-temp;
				if(temp==index||0==index)
				{
					out.push_back(vector<int>(out[k]));
					out.back().push_back(S[i]);
				}
			}
		}
		return out;
    }
};

int main()
{
	return 0;
}