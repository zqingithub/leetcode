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
    bool isBalanced(TreeNode* root)
    {
        int temp;
        return recIsBalanced(root, temp);
    }
private:
    bool recIsBalanced(TreeNode* root,int &height)
    {
        if(root==NULL)
        {
            height=0;
            return true;
        }
        int left,right;
        if(recIsBalanced(root->left,left)&&recIsBalanced(root->right, right))
        {
            height=1+(left>right?left:right);
            if((right-left)*(right-left)<=1)
                return true;
            else
                return false;
        }
        height=1+(left>right?left:right);
        return false;
    }
};

int main()
{
    return 0;
}
