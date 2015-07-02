import java.util.ArrayList;
import java.util.LinkedList;
public class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) 
    {
    	int inDegree[]=new int[numCourses];
    	ArrayList<ArrayList<Integer>> adjList=
    			new ArrayList<ArrayList<Integer>>(numCourses);
    	for(int i=0;i<numCourses;++i)
    		adjList.add(new ArrayList<Integer>());
    	LinkedList<Integer> zeroIn=new LinkedList<Integer>();
    	int count=0;
    	int size=prerequisites.length;
    	for(int i=0;i<size;++i)
    	{
    		adjList.get(prerequisites[i][1]).add(prerequisites[i][0]);
    		inDegree[prerequisites[i][0]]++;
    	}
    	for(int i=0;i<numCourses;++i)
    		if(inDegree[i]==0)
    			zeroIn.add(i);
    	while(!zeroIn.isEmpty())
    	{
    		int temp=zeroIn.pop();
    		++count;
    		for(int itemp:adjList.get(temp))
    		{
    			--inDegree[itemp];
    			if(inDegree[itemp]==0)
    				zeroIn.add(itemp);
    		}
    	}
    	return count==numCourses;
    			
    }
}
