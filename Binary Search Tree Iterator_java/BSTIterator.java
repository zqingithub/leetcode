import java.util.Stack;
class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;

	TreeNode(int x) {
		val = x;
	}
}


public class BSTIterator {

    public BSTIterator(TreeNode root) {
        if(root==null)
        	return;
        TreeNode temp=root;
        while(temp!=null)
        {
        	inorder.add(temp);
        	temp=temp.left;
        }
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
    	return !inorder.isEmpty();
    }

    /** @return the next smallest number */
    public int next() {
        TreeNode temp=inorder.pop();
        int outcome=temp.val;
        temp=temp.right;
        while(temp!=null)
        {
        	inorder.add(temp);
        	temp=temp.left;
        }
        return outcome;
    }
    
    private Stack<TreeNode> inorder=new Stack<TreeNode>();
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = new BSTIterator(root);
 * while (i.hasNext()) v[f()] = i.next();
 */