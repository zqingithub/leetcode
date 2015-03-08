#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k)
    {
    	vector<vector<int> >out;
    	vector<int> store(k);
    	recCom(n,1,1,store,out);
    	return out;
    }

private:
    void recCom(int n,int k,int index,vector<int>& store,vector<vector<int> >& out)
    {
    	if(k==store.size()+1)
    	{
    		out.push_back(store);
    		return;
    	}
    	for(int i=index;i<=n-(store.size()-k);++i)
    	{
    		store[k-1]=i;
    		recCom(n,k+1,i+1,store,out);
    	}
    }
};

int main()
{
	return 0;
}




