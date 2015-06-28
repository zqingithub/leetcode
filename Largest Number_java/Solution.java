import java.util.*;
public class Solution {
    public String largestNumber(int[] nums) {
        StringBuilder outcome=new StringBuilder();
        List<String> strList=new ArrayList<String>();
        for(int temp:nums)
        	strList.add(new Integer(temp).toString());
        Collections.sort(strList,new Comparator<String>()
        {
        	public int compare(String s1,String s2)
        	{
        		int size=s1.length(),i=0;
        		if(s1.length()>s2.length())
        		{
        			size=s2.length();
        		}
        		while(i<size&&s1.charAt(i)==s2.charAt(i))++i;
        		if(i<size)
        			return s1.charAt(i)-s2.charAt(i);
        		else
        		{
        			if(s1.length()==s2.length())
        				return 0;
        			if(s1.length()>s2.length())
        				return compare(s1.substring(i),s2);
        			else
        				return compare(s1,s2.substring(i));
        		}
        		
        	}
        }
        );
        for(int i=strList.size()-1;i>=0;--i)
        	outcome.append(strList.get(i));
        if(outcome.charAt(0)=='0')
        	return "0";
        return outcome.toString();
    }
}
