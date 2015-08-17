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
    int maxDepth(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int leftDeep=maxDepth(root->left);
        int rightDeep=maxDepth(root->right);
        return 1+(leftDeep>rightDeep?leftDeep:rightDeep);
    }
};

int main()
{
    return 0;
}
