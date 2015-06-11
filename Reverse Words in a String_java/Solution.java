public class Solution {
    public String reverseWords(String s) {
    	s=s.trim();
    	String store[]=s.split("\\s+");
    	StringBuilder buffer=new StringBuilder();
    	if(store.length==0)
    		return s;
    	int size=store.length;
    	buffer.append(store[size-1]);
    	for(int i=size-2;i>=0;--i)
    		buffer.append(" "+store[i]);
    	return buffer.toString();
    }
}
