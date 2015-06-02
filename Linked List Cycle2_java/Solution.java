class ListNode 
 {
      int val;
      ListNode next;
      ListNode(int x) {
          val = x;
         next = null;
      }
 }

public class Solution {
	public ListNode detectCycle(ListNode head) 
    {
		if(head==null)
			return null;
		ListNode first=head,second=head;
		while(second.next!=null&&second.next.next!=null)
		{
			first=first.next;
			second=second.next.next;
			if(first==second)
			{
				first=head;
				while(first!=second)
				{
					first=first.next;
					second=second.next;
				}
				return first;
			}
		}
		return null;
    }
}
