#include<iostream>
using  namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int minDepth(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int left=minDepth(root->left);
        int right=minDepth(root->right);
        if(left==0)
            return 1+right;
        if(right==0)
            return 1+left;
        return 1+(left<right?left:right);
    }
};

int main()
{
    return 0;
}
