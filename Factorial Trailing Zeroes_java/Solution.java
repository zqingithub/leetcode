public class Solution {
    public int trailingZeroes(int n) 
    {
    	int outcome=0;
    	while(n!=0)
    	{
    		outcome+=n/5;
    		n=n/5;
    	}
    	return outcome;
    }
}