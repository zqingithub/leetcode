#include<iostream>
#include<Windows.h>
using namespace std;

 struct ListNode 
 {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {

		if(head==NULL)
			return head;
		ListNode * temp=head;
		int n=0;
		while(temp!=NULL)
		{
			++n;
			temp=temp->next;
		}
		k=k%n;
		if(k==0)
			return head;
		ListNode * end=head;
		while(k-->0)
		{
			end=end->next;
		}
		temp=head;
		while(end->next!=NULL)
		{
			temp=temp->next;
			end=end->next;
		}
		ListNode * out=temp->next;
		temp->next=NULL;
		end->next=head;
        return out;
    }
};

int main()
{
	return 0;
}