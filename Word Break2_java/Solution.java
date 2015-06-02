import java.util.*;
public class Solution {
    public List<String> wordBreak(String s, Set<String> wordDict) 
    {
    	List<String> outcome=new ArrayList<String>();
    	int size=s.length();
    	if(size==0)
    		return outcome;
    	boolean state[]=new boolean[size+1];
    	Arrays.fill(state, false);
    	state[0]=true;
    	for(int i=1;i<=size;++i)
    	{
    		for(int k=i;k>0;--k)
    		{
    			if(wordDict.contains(s.substring(k-1, i))&&state[k-1])
    			{
    				state[i]=true;
    				break;
    			}
    				
    		}
    	}
    	if(!state[size])
    		return outcome;
    	else
    	{
    		List<StringBuilder> strList=getString(size,s,wordDict,state);
    		for(StringBuilder strBuil:strList)
    		{
    			outcome.add(strBuil.toString());
    		}
    	}
    	return outcome;
    }
    private List<StringBuilder> getString(final int index,String s,Set<String> wordDict,boolean state[])
    {
    	if(index==0)
    		return null;
    	List<StringBuilder> outcome=new ArrayList<StringBuilder>();
    	List<StringBuilder> subList;
    	for(int i=index;i>0;--i)
    	{
    		String str=s.substring(i-1,index);
    		if(wordDict.contains(str)&&state[i-1])
    		{
    			subList=getString(i-1,s,wordDict,state);
    			if(subList==null)
    			{
    				outcome.add(new StringBuilder(str));
    			}
    			else
    			{
    				for(StringBuilder strbu:subList)
    				{
    					strbu.append(" "+str);
    					outcome.add(strbu);
    				}
    			}
    		}
    	}
    	return outcome;
    }
}