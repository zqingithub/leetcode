#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) 
	{
		for(int i=0;i<matrix.size();++i)
			for(int k=i;k<matrix.size();++k)
				swap(matrix[i][k],matrix[k][i]);
		for(int i=0;i<matrix.size();++i)
			for(int k=0;k<matrix.size()/2;++k)
				swap(matrix[i][k],matrix[i][matrix.size()-1-k]);
    }
};
int main()
{
	return 0;
}