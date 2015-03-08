#include<iostream>
#include<memory.h>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T)
    {
    	memset(store,0,sizeof(int)*256);
    	memset(index,0,sizeof(int)*256);
    	for(int i=0;i<T.size();++i)
    		++index[T[i]];
    	int start=0,end=0;
    	int Max=-1,Max_s,Max_e;
    	while(end<S.size())
    	{
    		++store[S[end]];
    		if(isInclude())
    		{
    			while(isInclude())
    			{
    				--store[S[start]];
    				++start;
    			}

				if(-1==Max||end-start+2<Max)
				{
					Max=end-start+2;
					Max_s=start-1;
					Max_e=end;
				}
    		}
    		++end;
    	}

    	if(-1==Max)
    		return "";
    	else
    		return S.substr(Max_s,Max_e-Max_s+1);


    }
private:
	int store[256];
	int index[256];
    bool isInclude()
    {
    	for(int i=0;i<256;++i)
    		if(index[i]>0&&store[i]<index[i])
    			return false;
    	return true;
    }
};

int main()
{
	cout<<Solution().minWindow("bba", "ab")<<endl;
	cout<<"test"<<endl;
	return 0;
}




