#include<iostream>
using namespace std;


struct ListNode
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *partition(ListNode *head, int x)
	{
		if(NULL==head)
			return NULL;
		ListNode *pre,*lh,*lp,*mh,*mp,*temp;
	    lh=lp=mh=mp=NULL;
		pre=head;
		while(pre!=NULL)
		{
			if(pre->val<x)
				if(NULL==lh)
					lh=lp=pre;
				else
				{
					lp->next=pre;
					lp=pre;
				}
			else
				if(NULL==mh)
					mh=mp=pre;
				else
				{
					mp->next=pre;
					mp=pre;
				}
			pre=pre->next;
		}
		if(NULL!=lp)
			lp->next=mh;
		if(NULL!=mp)
			mp->next=NULL;
		if(NULL!=lh)
			return lh;
		if(NULL!=mh)
			return mh;
    }
};
int main()
{
	return 0;
}