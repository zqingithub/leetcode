#include<iostream>
#include<vector>
#include<stack>
using namespace std;


 
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root)
	{
		vector<vector<int> >out;
		if(NULL==root)
			return out;
		bool sign=true;
		stack<TreeNode*> *next=new stack<TreeNode*>();
		stack<TreeNode*> *work=new stack<TreeNode*>();
		work->push(root);
		while(!work->empty())
		{
			out.push_back(vector<int>());
			sign=sign?false:true;
			while(!work->empty())
			{
				TreeNode *temp=work->top();
				work->pop();
				out.back().push_back(temp->val);
				if(sign)
				{
					if(NULL!=temp->right)
						next->push(temp->right);
					if(NULL!=temp->left)
						next->push(temp->left);
				}
				else
				{					
					if(NULL!=temp->left)
						next->push(temp->left);
					if(NULL!=temp->right)
						next->push(temp->right);
				}
			}
			stack<TreeNode*> *temp=work;
			work=next;
			next=temp;
		}
		delete work;
		delete next;
		return out;
    }
};

int main()
{
	return 0;
}