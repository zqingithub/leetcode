public class Solution {
    public int titleToNumber(String s) 
    {
    	int outcome=0;
    	int size=s.length();
    	int multi=1;
    	for(int i=size-1;i>=0;--i)
    	{
    		outcome+=(s.charAt(i)-'A'+1)*multi;
    		multi*=26;
    	}
    	return outcome;
    }
}