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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        return recBuild(inorder, postorder, 0,inorder.size()-1, 0, postorder.size()-1);
    }
private:
    TreeNode* recBuild(vector<int> &inorder,vector<int> &postorder,const int si,const int ei,const int sp,const int ep)
    {
        if(si>ei)
            return NULL;
        int value=postorder[ep];
        TreeNode *root=new TreeNode(value);
        int i=si;
        for(;i<=ei;++i)
        {
            if(inorder[i]==value)
                break;
        }
        root->left=recBuild(inorder, postorder, si, i-1, sp, sp+(i-1-si));
        root->right=recBuild(inorder, postorder, i+1, ei, sp+(i-si), ep-1);
        return root;
    }
};

int main()
{
    return 0;
}