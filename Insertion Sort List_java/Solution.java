class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
	}
}

public class Solution {
    public ListNode insertionSortList(ListNode head)
    {
    	ListNode outcome=null;
    	ListNode pre,work,iter,store;
    	iter=head;
    	while(iter!=null)
    	{
    		store=iter.next;
    		pre=null;
    		work=outcome;
    		while(work!=null&&work.val<=iter.val)
    		{
    			work=work.next;
    			if(pre==null)
    				pre=outcome;
    			else
    				pre=pre.next;
    		}
    		if(pre==null)
    		{
    			iter.next=outcome;
    			outcome=iter;
    		}
    		else
    		{
    			pre.next=iter;
    			iter.next=work;
    		}
    		iter=store;
    	}
    	return outcome;
    }
}