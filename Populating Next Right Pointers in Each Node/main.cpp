#include<iostream>
#include<queue>
using namespace std;


struct TreeLinkNode 
{
int val;
TreeLinkNode *left, *right, *next;
TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) 
	{
		if(NULL==root)
			return;
		queue<TreeLinkNode*> myque;
		myque.push(root);
		myque.push(NULL);
		TreeLinkNode *work=NULL;
		while(!myque.empty())
		{
			TreeLinkNode *temp=myque.front();
			myque.pop();
			if(NULL==temp)
			{
				work->next=NULL;
				if(!myque.empty())
				{
					myque.push(NULL);
					work=NULL;
				}
			}
			else
			{
				if(NULL!=work)
					work->next=temp;
				work=temp;
				if(NULL!=work->left)
					myque.push(work->left);
				if(NULL!=work->right)
					myque.push(work->right);

			}

		}

    }
};

int main()
{
	TreeLinkNode *root=new TreeLinkNode(0);
	Solution().connect(root);
	return 0;
}

