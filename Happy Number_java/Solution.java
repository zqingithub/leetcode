import java.util.HashSet;
import java.util.Set;

public class Solution {
    public boolean isHappy(int n) {      
    	Set<Integer> record=new HashSet<Integer>();
    	while(n!=1)
    	{
    		if(record.contains(n))
    			break;
    		record.add(n);
    		int temp=0;
    		while(n!=0)
    		{
    			temp+=(n%10)*(n%10);
    			n/=10;
    		}
    		n=temp;
    	}
    	return n==1;
    }
}