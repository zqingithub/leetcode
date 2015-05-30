import java.util.*;
 class UndirectedGraphNode
 {
     int label;
     List<UndirectedGraphNode> neighbors;
     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 }

public class Solution {
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) 
    {
       if(node==null)
    	   return null;
       UndirectedGraphNode outcome=store.get(node.label);
       if(outcome!=null)
    	   return outcome;
       outcome=new UndirectedGraphNode(node.label);
       store.put(node.label, outcome);
       for(UndirectedGraphNode temp:node.neighbors)
       {
    	   UndirectedGraphNode isCreate=store.get(temp.label);
    	   if(isCreate!=null)
    		   outcome.neighbors.add(isCreate);
    	   else
    		   outcome.neighbors.add(cloneGraph(temp));
       }
       return outcome;
    }
    private HashMap<Integer,UndirectedGraphNode> store=
    		new HashMap<Integer,UndirectedGraphNode>();
}