class TrieNode {
    public TrieNode() 
    {     
    }
    TrieNode[] next=new TrieNode[26];
    boolean isWord=false;
}

public class Trie {
    private TrieNode root;
    public Trie() {
        root = new TrieNode();
    }
    public void insert(String word) {
    	int size=word.length();
    	if(size==0)
    		return;
    	TrieNode prt=root;
    	for(int i=0;i<size;++i)
    	{
    		if(prt.next[word.charAt(i)-'a']==null)
    			prt.next[word.charAt(i)-'a']=new TrieNode();
    		prt=prt.next[word.charAt(i)-'a'];
    	}
    	prt.isWord=true;
    }
    public boolean search(String word) 
    {      
    	int size=word.length();
    	if(size==0)
    		return false;
    	TrieNode prt=root;
    	for(int i=0;i<size;++i)
    	{
    		if(prt.next[word.charAt(i)-'a']==null)
    			return false;
    		prt=prt.next[word.charAt(i)-'a'];
    	}
    	return prt.isWord;
    }
    public boolean startsWith(String prefix) 
    {
    	int size=prefix.length();
    	if(size==0)
    		return false;
    	TrieNode prt=root;
    	for(int i=0;i<size;++i)
    	{
    		if(prt.next[prefix.charAt(i)-'a']==null)
    			return false;
    		prt=prt.next[prefix.charAt(i)-'a'];
    	}
    	return true;
    }
}
