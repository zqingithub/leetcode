#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) 
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
		set<int> record;
		for(int i=index;i<num.size();++i)
		{
			if(record.find(num[i])==record.end())
				record.insert(num[i]);
			else
				continue;
			swap(num[i],num[index]);
			minPermute(num,index+1,out);
			swap(num[i],num[index]);
		}
	}
};

int main()
{
	vector<vector<int> > out;
	vector<int> num;
	num.push_back(-1);
	num.push_back(-1);
	num.push_back(3);
	num.push_back(-1);
	out=(new Solution())->permuteUnique(num);
	return 0;
}