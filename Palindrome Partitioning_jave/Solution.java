import java.util.*;

public class Solution {
    public List<List<String>> partition(String s) 
    {
    	List<List<String>> outcome=new ArrayList<List<String>>();
    	int size=s.length();
    	String temp;
    	List<List<String>> listTemp;
    	for(int i=1;i<=size;++i)
    	{
    		temp=s.substring(0,i);
    		if(isPalindrome(temp))
    		{
    			listTemp=partition(s.substring(i,size));
    			if(listTemp.isEmpty())
    			{
    				outcome.add(new LinkedList<String>());
    				outcome.get(outcome.size()-1).add(temp);
    			}
    			else
    			{
    				for(List<String> LsTemp:listTemp)
    				{
    					LsTemp.add(0, temp);
    					outcome.add(LsTemp);
    				}
    			}
    		}
    	}
    	return outcome;
    }
    private boolean isPalindrome(String s)
    {
    	int mid=s.length()/2;
    	int size=s.length();
    	for(int i=0;i<=mid;++i)
    		if(s.charAt(i)!=s.charAt(size-1-i))
    			return false;
    	return true;
    }
}