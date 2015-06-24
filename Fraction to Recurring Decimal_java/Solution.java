import java.util.HashMap;
public class Solution {
    public String fractionToDecimal(int numerator, int denominator) 
    {
        StringBuilder outcome=new StringBuilder();
        if(numerator<0&&denominator>0||numerator>0&&denominator<0)
        	outcome.append('-');
        long Numerator=Math.abs((long)numerator);
        long Denominator=Math.abs((long)denominator);
        long remain=Numerator%Denominator;
        outcome.append(Numerator/Denominator);
        if(remain!=0)
        	outcome.append('.');
        StringBuilder decimal=new StringBuilder();
        int count=0;
        HashMap<Long,Integer> record=new HashMap<Long,Integer>();
        while(remain!=0)
        {
        	if(record.containsKey(remain))
        	{
        		decimal.insert(record.get(remain).intValue(), '(');
        		decimal.append(')');
        		break;
        	}
        	else
        	{
        		record.put(remain, count++);
        		decimal.append(remain*10/Denominator);
        		remain=remain*10%Denominator;
        	}
        }
        outcome.append(decimal);
        return outcome.toString();
    }
}