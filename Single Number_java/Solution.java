public class Solution {
    public int singleNumber(int[] nums) 
    {
    	int outcome=0;
    	for(int temp:nums)
    		outcome^=temp;
    	return outcome;
    }
}