public class Solution {
    public int minCut(String s) 
    {
    	int size=s.length();
    	if(size==0)
    		return 0;
    	boolean isPal[][]=new boolean[size][size];
    	int minStore[]=new int[size+1];
    	for(int i=0;i<size;++i)
    		isPal[i][i]=true;
    	for(int i=0;i<=size-2;++i)
    		if(s.charAt(i)==s.charAt(i+1))
    			isPal[i][i+1]=true;
    	for(int L=3;L<=size;++L)
    		for(int i=0;i<=size-L;++i)
    		{
    			if(s.charAt(i)==s.charAt(i+L-1)&&isPal[i+1][i+L-2])
    				isPal[i][i+L-1]=true;
    		}
    	minStore[size]=-1;
    	for(int i=size-1;i>=0;--i)
    	{
    		minStore[i]=size-i-1;
    		for(int j=i;j<size;++j)
    			if(isPal[i][j])
    				if(1+minStore[j+1]<minStore[i])
    					minStore[i]=1+minStore[j+1];
    			
    	}
    	return minStore[0];
    }
}
