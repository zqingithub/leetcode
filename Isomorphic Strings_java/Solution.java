import java.util.HashMap;
import java.util.Map;

public class Solution {
    public boolean isIsomorphic(String s, String t) {
    	if(s.length()!=t.length())
    		return false;
    	Map<Character,Character> record=new HashMap<Character,Character>();
 
    	int size=s.length();   	
    	for(int j=0;j<2;++j)
    	{
    		String temp=s; 
    		s=t;t=temp;
        	record.clear();
        	for(int i=0;i<size;++i)
        	{
    			if(!record.containsKey(s.charAt(i)))
    				record.put(s.charAt(i), t.charAt(i));
    			else
    				if(record.get(s.charAt(i))!=t.charAt(i))
    					return false;
        	}
        	
    	}
    	return true;	
    }
}