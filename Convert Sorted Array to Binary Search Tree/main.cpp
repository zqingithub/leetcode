#include<iostream>
#include<vector>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &num) 
	{
		if(0==num.size())
			return NULL;
		return rec(0,num.size()-1,num);
    }
private:
	TreeNode* rec(const int s,const int e,const vector<int> &num)
	{
		if(s>e)
			return NULL;
		int mid=(s+e)/2;
		TreeNode *out=new TreeNode(num[mid]);
		out->left=rec(s,mid-1,num);
		out->right=rec(mid+1,e,num);
		return out;
	}
};

int main()
{
	return 0;
}