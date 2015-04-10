#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    void recoverTree(TreeNode *root) 
	{
		wNode1=wNode2=pre=NULL;
		rec(root);
		wNode1->val^=wNode2->val;
		wNode2->val=wNode1->val^wNode2->val;
		wNode1->val^=wNode2->val;
    }
private:
	void rec(TreeNode *root)
	{
		if(NULL!=root->left)
			rec(root->left);
		if(NULL!=pre)
		{
			if(root->val<pre->val)
			{
				if(NULL==wNode1)
					wNode1=pre;
			    wNode2=root;
			}
		}
	    pre=root;
		if(NULL!=root->right)
			rec(root->right);
	}
	TreeNode *wNode1;
	TreeNode *wNode2;
	TreeNode *pre;
};

int main()
{
	return 0;
}