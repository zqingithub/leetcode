public class Solution {
    public int countPrimes(int n) {
    	boolean isPrime[]=new boolean[n];
    	int count=0;
    	for(int i=2;i<n;++i)
    	{
    		if(!isPrime[i])
    		{
    			++count;
    			for(int j=2;j*i<n;++j)
    				isPrime[j*i]=true;
    		}
    	}
    	return count;
    }
}