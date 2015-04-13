#include<iostream>
#include<vector>
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int> >out;
		if(NULL==root)
			return out;
		vector<int> store;
		rec(root,sum,store,out);
		return out;
    }
private:
	void rec(TreeNode * root,const int sum,vector<int> &store,vector<vector<int> > &out)
	{
		if(root->val==sum&&root->left==NULL&&root->right==NULL)
		{
			store.push_back(root->val);
			out.push_back(store);
			store.pop_back();
			return;
		}
		store.push_back(root->val);
		if(NULL!=root->left)
			rec(root->left,sum-root->val,store,out);
		if(NULL!=root->right)
			rec(root->right,sum-root->val,store,out);
		store.pop_back();

	}
};


int main()
{
	return 0;
}