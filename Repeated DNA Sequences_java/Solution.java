import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
public class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        List<String> outcome=new ArrayList<String>();
        int size=s.length();
        if(size<10)
        	return outcome;
        Map<Integer,Integer> record=new HashMap<Integer,Integer>(1024*1024);
        int value=0;
        int trans[]=new int[26];
        trans['A'-'A']=0;
        trans['C'-'A']=1;
        trans['G'-'A']=2;
        trans['T'-'A']=3;
        for(int i=0;i<10;++i)
        {
        	value<<=2;
        	value+=trans[s.charAt(i)-'A'];
        }
        record.put(value,1);
        for(int i=10;i<size;++i)
        {
        	value<<=2;
        	value+=trans[s.charAt(i)-'A'];
        	value&=0xFFFFF;
        	if(record.containsKey(value))
        	{
        		if(record.get(value)==1)
        		{
            		outcome.add(s.substring(i-9,i+1));
            		record.put(value, 2);
        		}
        	}
        	else
        		record.put(value,1);
        }
        return outcome;
    }
}