#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) 
	{
		vector<vector<int> > out;
		minPermute(num,0,out);
		return out;
        
    }
private:
	void minPermute(vector<int> & num,int index,vector<vector<int> >& out)
	{
		if(index==num.size()-1)
		{
			out.push_back(num);
			return;
		}
		for(int i=index;i<num.size();++i)
		{
			swap(num[i],num[index]);
			minPermute(num,index+1,out);
			swap(num[i],num[index]);
		}
	}
};

int main()
{
	return 0;
}