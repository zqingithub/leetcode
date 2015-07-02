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
    ListNode* reverseList(ListNode* head) {
    	if(NULL==head)
    		return NULL;
    	ListNode *pre=NULL,*prt=head,*temp;
    	while(prt!=NULL)
    	{
    		temp=prt->next;
    		prt->next=pre;
    		pre=prt;
    		prt=temp;
    	}
    	return pre;
    }
};

int main()
{
	return 0;
}


