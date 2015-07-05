public class WordDictionary {
    public void addWord(String word) {
    	Node prt=root;
    	int size=word.length();
    	for(int i=0;i<size;++i)
    	{
    		int temp=word.charAt(i)-'a';
    		if(prt.next[temp]==null)
    			prt.next[temp]=new Node();
    		prt=prt.next[temp];
    	}
    	prt.isEnd=true;
    }
    public boolean search(String word) {
    	return recSearch(word,root);
    }
    private boolean recSearch(String word,Node root)
    {
    	int size=word.length();
    	Node prt=root;
    	char temp;
    	for(int i=0;i<size;++i)
    	{
    		temp=word.charAt(i);
    		if(temp!='.')
    		{
    			if(prt.next[temp-'a']==null)
    				return false;
    			prt=prt.next[temp-'a'];
    		}
    		else
    		{
    			String stemp=word.substring(i+1, word.length());
    			for(char c='a';c<='z';++c)
    			{
    				if(recSearch(c+stemp,prt))
    					return true;
    			}
    			return false;
    		}
    	}
    	return prt.isEnd;
    }
    private class Node
    {
    	Node next[]=new Node[26];
    	boolean isEnd=false;
    }
    private Node root=new Node();
}
