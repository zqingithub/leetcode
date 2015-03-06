#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {
    	int row,col;
        row=matrix.size();
        col=matrix[0].size();
        int i,j;
        i=0; j=col-1;
        while(i<row&&j>=0)
        {
        	if(matrix[i][j]==target)
        		return true;
        	if(matrix[i][j]<target)
        		++i;
        	else
        		--j;
        }
        return false;
    }
};

int main()
{
	return 0;
}



