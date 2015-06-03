class ListNode 
{
	 int val;
	 ListNode next;
	 ListNode(int x) { val = x; }
}

public class Solution {
    public void reorderList(ListNode head) 
    {
    	if(head==null||head.next==null)
    		return;
        int n=0;
        ListNode temp=head,first,second;
        while(temp!=null)
        {
        	++n;
        	temp=temp.next;
        }
        n=n%2==0?n/2:n/2+1;
        first=head;
        for(int i=1;i<n;++i)
        	first=first.next;
        temp=first;
        first=first.next;
        temp.next=null;
        second=first.next;
        first.next=null;
        while(second!=null)
        {
        	temp=second.next;
        	second.next=first;
        	first=second;
        	second=temp;
        }
        second=first;
        first=head;
        while(second!=null)
        {
        	temp=first.next;
        	first.next=second;
        	second=second.next;
        	first.next.next=temp;
        	first=temp;
        }
    }
}
