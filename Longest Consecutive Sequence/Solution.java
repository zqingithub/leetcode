import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

public class Solution {
    public int longestConsecutive(int[] nums) 
    {
    	HashSet<Integer> newNum=new HashSet<Integer>(nums.length);
    	for(int temp:nums)
    		newNum.add(temp);
    	int Max=1;
    	Map<Integer,Integer> increase=new HashMap<Integer,Integer>(newNum.size());
    	Map<Integer,Integer> decrease=new HashMap<Integer,Integer>(newNum.size());
    	Integer up;
    	Integer down;
    	for(int temp:newNum)
    	{
    		up=increase.remove(temp+1);
    		down=decrease.remove(temp-1);
    		if(up==null&&down==null)
    		{
    			increase.put(temp, temp);
    			decrease.put(temp, temp);
    		}
    		if(up!=null&&down!=null)
    		{
    			increase.remove(down);
    			decrease.remove(up);
    			if(up-down+1>Max)
    				Max=up-down+1;
    			increase.put(down, up);
    			decrease.put(up, down);
    		}
    		if(up!=null&&down==null)
    		{
    			decrease.remove(up);
    			if(up-temp+1>Max)
    				Max=up-temp+1;
    			increase.put(temp, up);
    			decrease.put(up, temp);
    		}
    		if(up==null&&down!=null)
    		{
    			increase.remove(down);
    			if(temp-down+1>Max)
    				Max=temp-down+1;
    			increase.put(down, temp);
    			decrease.put(temp, down);
    		}
    	}
    	return Max;
    }
}