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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		if(0==preorder.size())
			return NULL;
		pre=&preorder;
		in=&inorder;
		return rec(0,preorder.size()-1,0,inorder.size()-1);
    }
private:
	vector<int> *pre;
	vector<int> *in;
	TreeNode* rec(int ps,int pe,int is,int ie)
	{
		if(ps>pe||is>ie)
			return NULL;
		int root_value=pre->at(ps);
		int index;
		for(int i=is;i<=ie;++i)
			if(in->at(i)==root_value)
			{
				index=i;
				break;
			}
		TreeNode *out=new TreeNode(root_value);
		out->left=rec(ps+1,ps+index-is,is,index-1);
		out->right=rec(ps+index-is+1,pe,index+1,ie);
		return out;
	}
};

int main()
{
	return 0;
}