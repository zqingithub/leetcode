#include<iostream>
#include<vector>
using namespace std;

#define min(a,b) ((a)<(b)?(a):(b))
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        int maxSqu=0,width=matrix[0].size(),length=matrix.size();
        vector<vector<int> > maxEdge(length+1,vector<int> (width+1,0));
        for(int i=1;i<=length;++i)
        {
            for(int j=1;j<=width;++j)
            {
                if(matrix[i-1][j-1]=='1')
                {
                    maxEdge[i][j]=min(min(maxEdge[i-1][j],maxEdge[i][j-1]),maxEdge[i-1][j-1])+1;
                    if(maxEdge[i][j]>maxSqu)
                    {
                        maxSqu=maxEdge[i][j];
                    }
                }
            }
        }
        return maxSqu*maxSqu;
    }
};

int main()
{
    return 0;
}
