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
    void flatten(TreeNode *root) 
	{
		if(NULL==root)
			return;
		rec(root);
        
    }
private:
	TreeNode* rec(TreeNode *root)
	{
		if(NULL==root->right&&NULL==root->left)
			return root;
		TreeNode *temp=NULL;
		if(NULL!=root->left)
			temp=rec(root->left);
		if(NULL==root->right)
		{
			root->right=root->left;
			root->left=NULL;
			return temp;
		}
		if(NULL==temp)
			return rec(root->right);
		temp->right=root->right;
		root->right=root->left;
		root->left=NULL;
		return rec(temp->right);
	}
};

int main()
{
	TreeNode *root=new TreeNode(1);
	root->right=new TreeNode(2);
	Solution().flatten(root);
	return 0;
}