import java.util.*;
public class Solution {
    public int candy(int[] ratings) 
    {
    	if(ratings.length==0)
    		return 0;
    	int size=ratings.length;
    	int temp[]=new int[ratings.length];
    	Arrays.fill(temp, 1);
    	for(int i=1;i<size;++i)
    		if(ratings[i]>ratings[i-1])
    			temp[i]=temp[i-1]+1;
    	int total=temp[size-1];
    	for(int i=size-2;i>=0;--i)
    	{
    		if(ratings[i]>ratings[i+1]&&temp[i+1]+1>temp[i])
    			temp[i]=temp[i+1]+1;
    		total+=temp[i];
    	}
    	return total;
    	
    }
}