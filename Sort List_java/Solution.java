class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
	}
}
 
public class Solution {
    public ListNode sortList(ListNode head) 
    {
    	if(head==null)
    		return null;
    	if(head.next==null)
    		return head;
    	ListNode front=head,back,temp,pre;
    	int n=0;
    	while(front!=null)
    	{
    		front=front.next;
    		++n;
    	}
    	n=n/2;
    	front=head;
    	while(--n>0)
    	{
    		front=front.next;
    	}
    	back=front.next;
    	front.next=null;
    	front=sortList(head);
    	back=sortList(back);
    	head=null;
    	pre=null;
    	while(front!=null&&back!=null)
    	{
    		if(front.val<=back.val)
    		{
    			temp=front;
    			front=front.next;
    		}
    		else
    		{
    			temp=back;
    			back=back.next;
    		}
    		if(head==null)
    			head=temp;
    		if(pre==null)
    			pre=temp;
    		else
    		{
    			pre.next=temp;
    			pre=temp;
    		}
    	}
    	if(front!=null)
    		temp=front;
    	else
    		temp=back;
    	if(head==null)
    		head=temp;
    	if(pre!=null)
    		pre.next=temp;
    	return head;
    }
}