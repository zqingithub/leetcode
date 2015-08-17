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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return false;
        if(sum==root->val&&root->left==NULL&&root->right==NULL)
            return true;
        bool left=hasPathSum(root->left, sum-root->val),
             right=hasPathSum(root->right, sum-root->val);
        return left||right;
    }
};

int main()
{
    return 0;
}
