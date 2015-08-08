#include<iostream>
#include<stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        stack<TreeNode*> travel;
        TreeNode *prt=root;
        while(prt!=NULL)
        {
            travel.push(prt);
            prt=prt->left;
        }
        while(!travel.empty())
        {
            ++count;
            if(count==k)
                return travel.top()->val;
            prt=travel.top()->right;
            travel.pop();
            while(prt!=NULL)
            {
                travel.push(prt);
                prt=prt->left;
            }
        }
        return -1;
    }
};

int main()
{
    return 0;
}
