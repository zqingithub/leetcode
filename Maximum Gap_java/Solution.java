public class Solution {
	private class unit
	{
		int min;
		int max;
	}
    public int maximumGap(int[] nums) 
    {
    	if(nums.length<2)
    		return 0;
    	unit bucket[]=new unit[nums.length];
    	int max=nums[0],min=nums[0];
    	for(int temp:nums)
    	{
    		max=temp>max?temp:max;
    		min=temp<min?temp:min;
    	}
    	int size=(int)Math.ceil((max-min)*1.0/(nums.length-1));
    	for(int temp:nums)
    	{
    		int index=(temp-min)/size;
    		if(bucket[index]==null)
    		{
    			bucket[index]=new unit();
    			bucket[index].max=bucket[index].min=temp;
    		}
    		else
    		{
    			if(temp<bucket[index].min) bucket[index].min=temp;
    			if(temp>bucket[index].max) bucket[index].max=temp;
    		}
    	}
    	int maxDif=0;
    	unit pre=null;
    	for(unit temp:bucket)
    	{
    		if(temp!=null)
    		{
    			if(pre!=null)
    				maxDif=temp.min-pre.max>maxDif?temp.min-pre.max:maxDif;
    			pre=temp;
    		}
    	}
    	return maxDif;
    }
}
