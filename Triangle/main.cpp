#include<iotream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle)
    {
    	if(0==triangle.size())
    		return 0;
    	vector<int> store=triangle.back();
    	for(int i=triangle.size()-2;i>=0;--i)
    	{
    		int size=triangle[i].size();
    		for(int k=0;k<size;++k)
    			store[k]=triangle[i][k]+(store[k]<store[k+1]?store[k]:store[k+1]);
    	}
    	return store[0];
    }
};

int main()
{
	return 0;
}



