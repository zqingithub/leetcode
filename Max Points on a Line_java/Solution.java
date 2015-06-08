import java.util.*;
import java.util.Map.Entry;
class Point {
	int x;
	int y;

	Point() {
		x = 0;
		y = 0;
	}

	Point(int a, int b) {
		x = a;
		y = b;
	}
}
public class Solution {
    public int maxPoints(Point[] points) {
    	if(points.length==0)
    		return 0;
    	Map<Double,Integer> store=new HashMap<Double,Integer>();
    	int Max=1,vertical=0,overlap=0;
    	double slope;
    	for(Point iter:points)
    	{
    		vertical=1;
    		store.clear();
    		overlap=0;
    		for(Point inIter:points)
    			if(inIter!=iter)
    			{
    				if(inIter.x==iter.x)
    					if(inIter.y==iter.y)
    						++overlap;
    					else
    						++vertical;
    				else
    				{
    					slope=(inIter.y-iter.y)*1.0/(inIter.x-iter.x);
    					if(store.containsKey(slope))
    						store.put(slope, store.get(slope)+1);
    					else
    						store.put(slope, 2);
    				}
    			}
    		if(vertical+overlap>Max)
    			Max=vertical+overlap;
    		for(Entry<Double,Integer> Miter:store.entrySet())
    		{
    			if(Miter.getValue()+overlap>Max)
    				Max=Miter.getValue()+overlap;
    		}
    	}
    	return Max;
        
    }
}