import java.util.*;
public class Solution {
    public boolean wordBreak(String s, Set<String> wordDict) 
    {
    	int size=s.length();
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
    	return state[size];
    }
}
