#include<iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) 
	{
       ListNode *m_head=head,*pre_head=NULL;
	   int index=m;
	   while(--index>0)
	   {
		   pre_head=m_head;
		   m_head=m_head->next;
	   }

	   ListNode *pre=m_head,*cur=m_head->next,*temp;
	   index=n-m;
	   while(index-->0)
	   {
		   temp=cur->next;
		   cur->next=pre;
		   pre=cur;
		   cur=temp;
	   }
	   m_head->next=cur;
	   if(NULL!=pre_head)
	   {
		   pre_head->next=pre;
		   return head;
	   }
	   else
		   return pre;


    }
};

int main()
{
	return 0;
}