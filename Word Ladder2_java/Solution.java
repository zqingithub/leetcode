import java.util.LinkedList;
import java.util.List;
import java.util.Set;
import java.util.ArrayList;
import java.util.TreeMap;
import java.util.TreeSet;
public class Solution {
    public List<List<String>> findLadders(String start, String end, Set<String> dict) 
    {
        TreeMap<String,ArrayList<String> > record=new TreeMap<String,ArrayList<String> >();
        for(String temp:dict)
        	record.put(temp,new ArrayList<String>());
        TreeSet<String> pre=new TreeSet<String>();
        TreeSet<String> now=new TreeSet<String>();
        List<List<String>> outcome=new ArrayList<List<String>>();
        pre.add(start);
        dict.remove(start);
        int size=end.length();
        boolean state=true;
        while(state&&!dict.isEmpty())
        {
        	for(String temp:pre)
        	{
        		char Array[]=temp.toCharArray();
        		for(int i=0;i<size;++i)
        			for(char c='a';c<='z';++c)
        			{
        				char ctemp=Array[i];
        				Array[i]=c;
        				String stemp=new String(Array);
        				if(dict.contains(stemp))
        				{
        					now.add(stemp);
        					record.get(stemp).add(temp);
        					if(stemp.equals(end))
        						state=false;
        				}
        				Array[i]=ctemp;
        			}
        	}
        	if(now.isEmpty())
        		break;
        	for(String temp:now)
        		dict.remove(temp);
        	TreeSet<String> temp=now;
        	now=pre;
        	pre=temp;
        	now.clear();
        }
        if(state==false)
        	outcome=DFS(end,start,record);
        return outcome;
    }
    private List<List<String> > DFS(String start,String end,TreeMap<String,? extends List<String>> record)
    {
    	List<List<String>> outcome=new ArrayList<List<String>>();
    	if(start.equals(end))
    	{
    		outcome.add(new LinkedList<String>());
    		outcome.get(0).add(end);
    	}
    	else
    	{
    		List<String> next=record.get(start);
    		for(String sTemp:next)
    		{
    			List<List<String>> outcomeTemp=DFS(sTemp,end,record);
    			for(List<String> lTemp:outcomeTemp)
    			{
    				lTemp.add(start);
    				outcome.add(lTemp);
    			}
    		}
    	}
    	return outcome;
    }
}