import java.util.*;
 class TreeNode {
     int val;
     TreeNode left;
     TreeNode right;
      TreeNode(int x) { val = x; }
  }
 
public class Solution {
    public List<Integer> preorderTraversal(TreeNode root)
    {
    	List<Integer> outcome=new LinkedList<Integer>();
    	if(root==null)
    		return outcome;
    	Stack<TreeNode> stack=new Stack<TreeNode>();
    	stack.add(root);
    	TreeNode temp;
    	while(!stack.empty())
    	{
    		temp=stack.pop();
    		outcome.add(temp.val);
    		if(temp.right!=null)
    			stack.add(temp.right);
    		if(temp.left!=null)
    			stack.add(temp.left);
    	}
    	return outcome;
    }
}