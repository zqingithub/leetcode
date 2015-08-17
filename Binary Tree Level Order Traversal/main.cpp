#include<iostream>
#include<vector>
#include<queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root)
    {
        vector<vector<int> > outcome;
        if(root==NULL)
            return outcome;
        queue<TreeNode*> store;
        store.push(root);
        store.push(NULL);
        outcome.push_back(vector<int> ());
        while(!store.empty())
        {
            if(store.front()==NULL)
            {
                store.pop();
                if(!store.empty())
                {
                    store.push(NULL);
                    outcome.push_back(vector<int> ());
                }
            }
            else
            {
                outcome.back().push_back(store.front()->val);
                if(store.front()->left!=NULL)
                    store.push(store.front()->left);
                if(store.front()->right!=NULL)
                    store.push(store.front()->right);
                store.pop();
            }
        }
        return outcome;
    }
};

int main()
{
    return 0;
}
