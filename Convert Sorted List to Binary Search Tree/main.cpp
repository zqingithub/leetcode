#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        int count=0;
        ListNode *prt=head;
        while(prt!=NULL)
        {
            ++count;
            prt=prt->next;
        }
        return recBuild(head, count);
    }
    TreeNode* recBuild(ListNode* head,const int n)
    {
        if(n==0)
            return NULL;
        if(n==1)
            return new TreeNode(head->val);
        int half=n/2;
        ListNode *prt=head;
        while(--half>0)prt=prt->next;
        TreeNode *root=new TreeNode(prt->next->val);
        root->left=recBuild(head, n/2);
        root->right=recBuild(prt->next->next, n-n/2-1);
        return root;
    }
};

int main()
{
    return 0;
}