#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};


class Solution {
public:
    vector<int> rightSideView(TreeNode* root)
	{
    	vector<int> outcome;
    	if(root==NULL)
    		return outcome;
    	queue<TreeNode*> bfs;
    	bfs.push(root);
    	bfs.push(NULL);
    	TreeNode *pre,*temp;
    	while(!bfs.empty())
    	{
    		temp=bfs.front();
    		bfs.pop();
    		if(NULL==temp)
    		{
    			if(!bfs.empty())
    				bfs.push(NULL);
    			outcome.push_back(pre->val);
    		}
    		else
    		{
    			pre=temp;
    			if(NULL!=temp->left) bfs.push(temp->left);
    			if(NULL!=temp->right) bfs.push(temp->right);
    		}
    	}
    	return outcome;
    }
};

int main()
{
	return 0;
}




