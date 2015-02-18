public class Solution {
    public boolean isNumber(String s) 
    {
    	try
    	{
    		s=s.toLowerCase();
    		Double.parseDouble(s);
    	}
    	catch(Exception e)
    	{
    		return false;
    	}
    	if(s.charAt(s.length()-1)=='d'||s.charAt(s.length()-1)=='f')
    		return false;
    	return true;
        
    }
}