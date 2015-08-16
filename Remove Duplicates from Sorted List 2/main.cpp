#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if(head==NULL)
            return NULL;
        ListNode myhead(0);
        myhead.next=head;
        ListNode *pre=&myhead,*temp;
        int store=head->val-1;
        while(pre->next!=NULL)
        {
            if(pre->next->next!=NULL&&pre->next->val==pre->next->next->val)
            {
                store=pre->next->val;
                temp=pre->next;
                pre->next=temp->next;
                delete temp;
            }
            else
            {
                if(pre->next->val==store)
                {
                    temp=pre->next;
                    pre->next=temp->next;
                    delete temp;
                }
                else
                {
                    pre=pre->next;
                }
            }
        }
        return myhead.next;
    }
};

int main()
{
    ListNode temp1(1);
    ListNode temp2(2);
    temp1.next=&temp2;
    Solution s;
    s.deleteDuplicates(&temp1);
    return 0;
}
