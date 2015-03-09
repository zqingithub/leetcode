#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S)
    {
    	sort(S.begin(),S.end());
    	vector<vector<int> >store;
    	bool * state=new bool[S.size()];
    	rec(0,S,store,state);
    	return store;
    }
private:
    void rec(int k,vector<int> &S,vector<vector<int> > &store,bool * state)
    {
    	if(k==S.size())
    	{
    		store.push_back(vector<int>());
    		for(int i=0;i<S.size();++i)
    		{
    			if(state[i])
    				store.back().push_back(S[i]);
    		}
    		return;
    	}
    	state[k]=false;
    	rec(k+1,S,store,state);
    	state[k]=true;
    	rec(k+1,S,store,state);

    }
};


int main()
{
	vector<int> S;
	S.push_back(0);
	vector<vector<int> >out;
	out=Solution().subsets(S);
	return 0;
}




