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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> store;
        TreeNode *prt=root;
        while(prt!=p)
        {
            store.push_back(prt);
            if(prt->val<p->val)
                prt=prt->right;
            else
                prt=prt->left;
        }
        store.push_back(prt);
        int i=0;
        prt=root;
        while(i<store.size())
        {
            if(prt!=store[i])
                return store[i-1];
            if(prt==q)
                return prt;
            ++i;
            if(prt->val<q->val)
                prt=prt->right;
            else
                prt=prt->left;
        }
        return store.back();
    }
};

int main()
{
    return 0;
}