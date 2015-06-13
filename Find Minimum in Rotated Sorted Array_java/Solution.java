public class Solution {
    public int findMin(int[] nums) 
    {
    	int size=nums.length;
    	int l=0,r=size-1,mid;
    	while(l!=r)
    	{
    		mid=(l+r)/2;
    		if(nums[mid]<nums[r])
    			r=mid;
    		else
    			l=mid+1;
    	}
    	return nums[l];
    }
}