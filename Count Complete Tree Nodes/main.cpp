#include<iostream>
#include<cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        int left=0,right=0;
        TreeNode * prt=root;
        while(prt!=NULL)
        {
            ++left;
            prt=prt->left;
        }
        prt=root;
        while(prt!=NULL)
        {
            ++right;
            prt=prt->right;
        }
        if(left==right)
        {
            return pow(2, left)-1;
        }
        else
        {
            return 1+countNodes(root->left)+countNodes(root->right);
        }
    }
};
int main()
{
    return 0;
}
