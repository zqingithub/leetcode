public class Solution {
    public int hammingWeight(int n) 
    {
    	int outcome=0;
    	while(n!=0)
    	{
    		n=n&(n-1);
    		++outcome;
    	}
    	return outcome;
    }
}