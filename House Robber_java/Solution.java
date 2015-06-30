public class Solution {

	public int rob(int[] nums) 
	{
		if(nums.length==0)
			return 0;
		int Max[]=new int[nums.length+1];
		Max[0]=0;Max[1]=nums[0];
	    int size=nums.length;
		for(int i=1;i<size;++i)
		{
			Max[i+1]=Math.max(nums[i]+Max[i-1], Max[i]);
		}
		return Max[size];
	}

}