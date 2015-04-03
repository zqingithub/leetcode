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
    vector<int> inorderTraversal(TreeNode *root) 
	{
        vector<int> out;
		rec(root,out);
		return out;
    }
private:
	void rec(TreeNode * root,vector<int>& store)
	{
		if(NULL==root)
			return;
		if(NULL!=root->left)
			rec(root->left,store);
		store.push_back(root->val);
		if(NULL!=root->right)
			rec(root->right,store);
	}
};

int main()
{
	return 0;
}