import java.util.*;
class RandomListNode 
{
  int label;
  RandomListNode next, random;
  RandomListNode(int x) { this.label = x; }
};
 
public class Solution {
    public RandomListNode copyRandomList(RandomListNode head) 
    {
    	if(head==null)
    		return null;
    	RandomListNode outcome=null;
    	List<RandomListNode> store=new ArrayList<RandomListNode>();
    	RandomListNode temp=head;
    	while(temp!=null)
    	{
    		store.add(temp);
    		temp=temp.next;
    	}
    	int size=store.size();
    	store.get(0).next=new RandomListNode(store.get(0).label);
    	for(int i=1;i<size;++i)
    	{
    		store.get(i).next=new RandomListNode(store.get(i).label);
    		store.get(i-1).next.next=store.get(i).next;
    	}
    	store.get(size-1).next.next=null;
    	for(int i=0;i<size;++i)
    		if(store.get(i).random==null)
    			store.get(i).next.random=null;
    		else
    			store.get(i).next.random=store.get(i).random.next;
    	outcome=store.get(0).next;
    	for(int i=0;i<size-1;++i)
    		store.get(i).next=store.get(i+1);
    	store.get(size-1).next=null;
    	return outcome;
    }
}