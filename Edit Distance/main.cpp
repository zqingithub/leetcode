#include<iostream>
#include<string>
using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
    	int * pre=new int[word2.size()+1];
    	int * now=new int[word2.size()+1];
   	for(string::size_type i=0;i<=word2.size();++i)
    		pre[i]=i;
    	for(string::size_type i=0;i<word1.size();++i)
    	{
    		now[0]=pre[0]+1;
    		for(string::size_type k=1;k<=word2.size();++k)
    		{
    			int index=word2[k-1]==word1[i]?0:1;
    			index+=pre[k-1];
    			int index2=pre[k]<now[k-1]?pre[k]:now[k-1];
    			index2+=1;
    			now[k]=index<index2?index:index2;
    		}
    		int * temp=pre;
    		pre=now;
    		now=temp;
    	}
    	int out=pre[word2.size()];
    	delete [] pre;
    	delete [] now;
    	return out;
    }
};

int main()
{
	cout<<Solution().minDistance("a", "ab")<<endl;
	return 0;
}
