public class Solution {
    public int maxProduct(int[] nums) 
    {
    	int min,max,record,tmax,tmin,temp;
    	min=max=record=nums[0];
    	int size=nums.length;
    	for(int i=1;i<size;++i)
    	{
    		tmin=nums[i]*min;
    		tmax=nums[i]*max;
    		if(tmin>tmax)
    		{
    			temp=tmin;
    			tmin=tmax;
    			tmax=temp;
    		}
    		if(tmin<nums[i])
    			min=tmin;
    		else
    			min=nums[i];
    		if(tmax>nums[i])
    			max=tmax;
    		else
    			max=nums[i];
    		
    		if(max>record)
    			record=max;
    	}
    	return record;
    }
}