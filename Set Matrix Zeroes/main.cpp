#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix)
    {
    	bool row,vol;
    	row=vol=false;
    	for(int i=0;i<matrix.size();++i)
    		if(matrix[i][0]==0)
    		{
    			vol=true;
    			break;
    		}
    	for(int i=0;i<matrix[0].size();++i)
    		if(matrix[0][i]==0)
    		{
    			row=true;
    			break;
    		}

    	for(int i=1;i<matrix.size();++i)
    	{
    		for(int j=1;j<matrix[0].size();++j)
    		{
    			if(matrix[i][j]==0)
    			{
    				matrix[0][j]=matrix[i][0]=0;
    			}
    		}
    	}
    	for(int i=1;i<matrix.size();++i)
    	{
    		for(int j=1;j<matrix[0].size();++j)
    		{
    			if(matrix[i][0]==0||matrix[0][j]==0)
    				matrix[i][j]=0;
    		}
    	}

    	if(vol)
        	for(int i=0;i<matrix.size();++i)
        		matrix[i][0]=0;
    	if(row)
        	for(int i=0;i<matrix[0].size();++i)
        		matrix[0][i]=0;
    }
};

int main()
{
	return 0;
}




