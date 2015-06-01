public class Solution {
    public int singleNumber(int[] nums) 
    {
    	int one=0,two=0,three;
    	for(int temp:nums)
    	{
    		two|=one&temp;
    		one^=temp;
    		three=one&two;
    		one&=~three;
    		two&=~three;
    	}
    	return one;
    }
}