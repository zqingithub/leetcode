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
    bool isSymmetric(TreeNode* root)
    {
        if(root==NULL)
            return true;
        return recIsSym(root->left, root->right);
    }
private:
    bool recIsSym(TreeNode *left,TreeNode *right)
    {
        if(left==NULL&&right==NULL)
            return true;
        if(left==NULL||right==NULL)
            return false;
        if(left->val==right->val)
            return recIsSym(left->left, right->right)&&recIsSym(left->right, right->left);
        else
            return false;
    }
};

int main()
{
    return 0;
}
