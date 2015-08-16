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
        ListNode myhead(0);
        myhead.next=head;
        ListNode *pre=&myhead,*temp;
        while(pre->next!=NULL)
        {
            if(pre->next->next!=NULL&&pre->next->val==pre->next->next->val)
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
        return myhead.next;
    }
};

int main()
{
    return 0;
}
