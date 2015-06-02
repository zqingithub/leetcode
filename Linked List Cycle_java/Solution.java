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
    public boolean hasCycle(ListNode head) 
    {
    	if(head==null)
    		return false;
    	ListNode first=head,second=head;
        boolean state=false;
        while(second!=null)
        {
        	second=second.next;
        	if(state)
        		first=first.next;
        	state=!state;
        	if(second==first)
        		return true;
        }
        return false;
    }
}