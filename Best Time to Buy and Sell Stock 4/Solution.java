public class Solution {
    public int maxProfit(int k, int[] prices) {
        int outcome=0;
        int size=prices.length;
        if(k>=size)
        {
        	for(int i=1;i<size;++i)
        		if(prices[i]-prices[i-1]>0)
        			outcome+=prices[i]-prices[i-1];
        	return outcome;
        }
        int opt[][]=new int[size+1][k+1];
        int temp[][]=new int[size+1][k+1];
        for(int i=2;i<=size;++i)
        	for(int j=1;j<=k;++j)
        	{
        		temp[i][j]=Math.max(opt[i-1][j-1], temp[i-1][j]+prices[i-1]-prices[i-2]);
        		opt[i][j]=Math.max(opt[i-1][j], temp[i][j]);
        	}
        return opt[size][k];
    }
}
