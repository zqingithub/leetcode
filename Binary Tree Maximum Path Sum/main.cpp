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
    int maxPathSum(TreeNode *root) 
	{
		if(NULL==root)
			return 0;
        int temp;
		return recMax(root,temp);
    }
private:
	int recMax(TreeNode *root,int &MaxFromRoot)
	{
		if(NULL==root->left&&NULL==root->right)
		{
			MaxFromRoot=root->val;
			return MaxFromRoot;
		}
		int leftMax,rightMax,leftMaxRoot,rightMaxRoot;
		if(NULL!=root->left)
			leftMax=recMax(root->left,leftMaxRoot);
		if(NULL!=root->right)
			rightMax=recMax(root->right,rightMaxRoot);
		if(NULL==root->left)
		{
			MaxFromRoot=root->val+rightMaxRoot;
			if(root->val>MaxFromRoot)
				MaxFromRoot=root->val;
			return MaxFromRoot>rightMax?MaxFromRoot:rightMax;
		}
		if(NULL==root->right)
		{
			MaxFromRoot=root->val+leftMaxRoot;
			if(root->val>MaxFromRoot)
				MaxFromRoot=root->val;
			return MaxFromRoot>leftMax?MaxFromRoot:leftMax;
		}
		MaxFromRoot=root->val+(rightMaxRoot>leftMaxRoot?rightMaxRoot:leftMaxRoot);
		if(root->val>MaxFromRoot)
			MaxFromRoot=root->val;
		int temp=leftMax>rightMax?leftMax:rightMax;
		temp<root->val+rightMaxRoot+leftMaxRoot?temp=root->val+rightMaxRoot+leftMaxRoot:temp=temp;
		return temp>MaxFromRoot?temp:MaxFromRoot;
	}
};

int main()
{
	return 0;
}