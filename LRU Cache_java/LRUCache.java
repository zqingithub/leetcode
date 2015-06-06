import java.util.*;

class ListUnit
{
	int key;
	int value;
	ListUnit pre;
	ListUnit next;
}

class VisitList
{
	ListUnit head=null;
	ListUnit tail=null;
	void insert(ListUnit newVisit)
	{
		newVisit.next=head;
		newVisit.pre=null;
		if(head!=null)
		    head.pre=newVisit;
		head=newVisit;
		if(tail==null)
			tail=newVisit;
	}
	void Visit(ListUnit visit)
	{
		if(visit==head)
			return;
		visit.pre.next=visit.next;
		if(visit!=tail)
			visit.next.pre=visit.pre;
		else
			tail=visit.pre;
		insert(visit);
	}
	void delete()
	{
		if(head==tail)
			head=tail=null;
		else
		{
			tail=tail.pre;
			tail.next.pre=null;
			tail.next=null;
		}
	}
}
public class LRUCache {
    
    public LRUCache(int capacity) {
        this.capacity=capacity;
    }
    
    public int get(int key) {
        ListUnit temp=map.get(key);
        if(temp==null)
        	return -1;
        else
        {
        	myList.Visit(temp);
        	return temp.value;
        }
    }
    
    public void set(int key, int value)
    {
        ListUnit temp=map.get(key);
        if(temp!=null)
        {
        	temp.value=value;
        	myList.Visit(temp);
        	return;
        }
        temp=new ListUnit();
        temp.key=key;
    	temp.value=value;
    	map.put(key, temp);
        if(size<capacity)
        {
        	++size;
        }
        else
        {
        	map.remove(myList.tail.key);
        	myList.delete();
        }
        myList.insert(temp);
    }
    
    private Map<Integer,ListUnit> map=new HashMap<Integer,ListUnit>();
    private int capacity;
    private int size=0;
    private VisitList myList=new VisitList();
}