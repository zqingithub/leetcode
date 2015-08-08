#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool isPalindrome(ListNode* head)
    {
        if(head==NULL)
            return true;
        ListNode * prt=head;
        int count=0;
        while(prt!=NULL)
        {
            ++count;
            prt=prt->next;
        }
        if(count==1)
            return true;
        prt=head;
        for(int i=count/2;i>0;--i)
        {
            prt=prt->next;
        }
        if(count%2!=0)
            prt=prt->next;
        prt=invert(prt);
        for(int i=count/2;i>0;--i)
        {
            if(prt->val!=head->val)
                return false;
            prt=prt->next;
            head=head->next;
        }
        return true;
        
    }
private:
    ListNode* invert(ListNode * begin)
    {
        ListNode * pre=NULL,*temp;
        while(begin!=NULL)
        {
            temp=begin->next;
            begin->next=pre;
            pre=begin;
            begin=temp;
        }
        return pre;
    }
};

int main()
{
    return 0;
}
