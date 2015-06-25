public class Solution {
    public int majorityElement(int[] nums) 
    {
    	int outcome=nums[0];
    	int count=0;
    	for(int temp:nums)
    	{
    		if(temp==outcome)
    			++count;
    		else
    		{
    			--count;
    			if(count==0)
    			{
    				count=1;
    				outcome=temp;
    			}
    		}
    	}
    	return outcome;
    }
}
