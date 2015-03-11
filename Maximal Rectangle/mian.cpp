#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix)
    {
    	if(0==matrix.size())
    		return 0;
    	vector<vector<int> > High;
    	for(int i=0;i<matrix.size();++i)
    		High.push_back(vector<int> (matrix.back().size()));
    	for(int i=0;i<matrix.back().size();++i)
    			High[0][i]=matrix[0][i]-'0';
    	int Max=findMax(High[0]);
    	for(int i=1;i<matrix.size();++i)
    	{
    		for(int k=0;k<matrix.back().size();++k)
    			if('1'==matrix[i][k])
    				High[i][k]=High[i-1][k]+1;
    			else
    				High[i][k]=0;
    		int temp=findMax(High[i]);
    		if(temp>Max)
    			Max=temp;
    	}
    	return Max;


    }
private:
    int findMax(vector<int> & V)
    {
    	vector<int> left(V.size());
    	vector<int> right(V.size());
    	left[0]=0;
    	for(int i=1;i<left.size();++i)
    	{
    		int index=i;
    		while(index>0&&V[index-1]>=V[i])
    			index=left[index-1];
    		left[i]=index;
    	}
    	right[right.size()-1]=right.size()-1;
    	for(int i=right.size()-2;i>=0;--i)
    	{
    		int index=i;
    		while(index<right.size()-1&&V[index+1]>=V[i])
    			index=right[index+1];
    		right[i]=index;
    	}
    	int Max=0;
    	for(int i=0;i<V.size();++i)
    	{
    		int temp=V[i]*(right[i]-left[i]+1);
    		if(temp>Max)
    			Max=temp;
    	}
    	return Max;
    }
};

int main()
{
	return 0;
}




