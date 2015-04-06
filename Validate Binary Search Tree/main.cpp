#include<iostream>
using namespace std;

 struct TreeNode 
 {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    bool isValidBST(TreeNode *root) {
		if(NULL==root)
			return true;
		int max,min;
		return rec(max,min,root);
        
    }
private:
	bool rec(int & max,int & min,TreeNode *root)
	{
		max=min=root->val;
		int Max,Min,temp;
		if(NULL!=root->left)
		{
			if(!rec(Max,temp,root->left))
				return false;
			if(Max>=root->val)
				return false;
			min=temp;
		}
		if(NULL!=root->right)
		{
			if(!rec(temp,Min,root->right))
				return false;
			if(Min<=root->val)
				return false;
			max=temp;
		}
		return true;
	}
};

int main()
{
	return 0;
}