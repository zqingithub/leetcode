class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
		next = null;
	}
}
 
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) 
    {
        if(headA==null||headB==null)
        	return null;
        int nA=0,nB=0;
        ListNode tempA,tempB;
        tempA=headA;
        while(tempA!=null)
        {
        	++nA;
        	tempA=tempA.next;
        }
        tempB=headB;
        while(tempB!=null)
        {
        	++nB;
        	tempB=tempB.next;
        }
        tempA=headA;
        tempB=headB;
        if(nA>nB)
        {
        	int dif=nA-nB;
        	while(dif-->0)
        		tempA=tempA.next;
        }
        else
        {
        	int dif=nB-nA;
        	while(dif-->0)
        		tempB=tempB.next;
        }
        while(tempA!=tempB)
        {
        	tempA=tempA.next;
        	tempB=tempB.next;
        }
        return tempA;
    }
}