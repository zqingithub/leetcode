import java.util.Stack;
public class Solution {
    public String convertToTitle(int n) {
    	Stack<Character> store=new Stack<Character>();
    	while(n!=0)
    	{
    		store.add(new Character((char)('A'+(n-1)%26)));
    		n=(n-1)/26;
    	}
    	StringBuilder outcome=new StringBuilder();
    	while(!store.isEmpty())
    		outcome.append(store.pop());
    	return outcome.toString();
    }
}