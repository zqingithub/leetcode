import java.util.*;
class MinStack {
    public void push(int x) {
        dataStack.add(x);
        if(minStack.isEmpty()||x<=minStack.get(minStack.size()-1))
        	minStack.add(x);
    }

    public void pop() {
        int temp=dataStack.remove(dataStack.size()-1);
        if(temp==minStack.get(minStack.size()-1))
        	minStack.remove(minStack.size()-1);
    }

    public int top() {
    	return dataStack.get(dataStack.size()-1);
        
    }

    public int getMin() {
    	return minStack.get(minStack.size()-1);
        
    }
    
    private List<Integer> dataStack=new ArrayList<Integer>();
    private List<Integer> minStack=new ArrayList<Integer>();
}
