import java.util.Stack;
public class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> store=new Stack<Integer>();
        int oper1,oper2;
        for(String iter:tokens)
        {
        	if(Character.isDigit(iter.charAt(0))||iter.length()>1)
        	{
        		store.add(Integer.parseInt(iter));
        		continue;
        	}
        	oper2=store.pop();
        	oper1=store.pop();
        	if(iter.equals("+"))
        	{
        		store.add(oper1+oper2);
        		continue;
        	}
        	if(iter.equals("-"))
        	{
        		store.add(oper1-oper2);
        		continue;
        	}
        	if(iter.equals("*"))
        	{
        		store.add(oper1*oper2);
        		continue;
        	}
        	if(iter.equals("/"))
        	{
        		store.add(oper1/oper2);
        		continue;
        	}
        }
        return store.pop();
    }
}