#include<iostream>
using namespace std;
 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    	ListNode temp(0);
    	ListNode *Head=&temp,*pre,*prt=head;
    	pre=Head;
    	Head->next=head;
    	while(prt!=NULL)
    	{
    		if(prt->val==val)
    		{
    			pre->next=prt->next;
    			delete prt;
    			prt=pre->next;
    		}
    		else
    		{
    			pre=prt;
    			prt=prt->next;
    		}
    	}
    	return Head->next;
    }
};

int main()
{
	return 0;
}




