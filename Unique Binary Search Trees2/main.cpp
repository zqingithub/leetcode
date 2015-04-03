#include<iostream>
#include<vector>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) 
	{
		if(0==n)
		{
			vector<TreeNode*> out;
			out.push_back(NULL);
			return out;
		}
        return rec(1,n);
    }
private:
	vector<TreeNode*> rec(const int s,const int e)
	{
		vector<TreeNode*> out;
		if(s==e)
		{
			out.push_back(new TreeNode(s));
			return out;
		}
		for(int i=s;i<=e;++i)
		{
			vector<TreeNode*> left;
			vector<TreeNode*> right;
			if(i!=s)
				left=rec(s,i-1);
			else
				left.push_back(NULL);
			if(i!=e)
				right=rec(i+1,e);
			else
				right.push_back(NULL);
			for(int x=0;x<left.size();++x)
				for(int y=0;y<right.size();++y)
				{
					out.push_back(new TreeNode(i));
					out.back()->left=left[x];
					out.back()->right=right[y];
				}

		}
		return out;
	}
};

int main()
{
	return 0;
}