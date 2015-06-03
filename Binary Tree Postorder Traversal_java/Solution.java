import java.util.*;
 class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x) { val = x; }
  }
 
 class VisitRecord
 {
	 TreeNode node;
	 boolean isVisit=false;
	 VisitRecord(TreeNode node)
	 {
		 this.node=node;
	 }
 }
public class Solution {
    public List<Integer> postorderTraversal(TreeNode root) 
    {
    	List<Integer> outcome=new LinkedList<Integer>();
    	if(root==null)
    		return outcome;
    	Stack<VisitRecord> stack=new Stack<VisitRecord>();
    	TreeNode temp=root;
    	while(temp!=null)
    	{
    		stack.add(new VisitRecord(temp));
    		temp=temp.left;
    	}
    	VisitRecord top;
    	while(!stack.empty())
    	{
    		top=stack.peek();
    		if(top.isVisit)
    		{
    			outcome.add(top.node.val);
    			stack.pop();
    		}
    		else
    		{
    			top.isVisit=true;
    			temp=top.node.right;
    			while(temp!=null)
    			{
    				stack.add(new VisitRecord(temp));
    				temp=temp.left;
    			}
    			
    		}
    	}
    	return outcome;
    }
}