import java.util.LinkedList;
import java.util.List;

public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) 
    {
    	List<Integer> Out=new LinkedList<Integer>();
    	if(matrix.length==0)
    		return Out;
    	int[] wall=new int[4];
    	wall[0]=matrix[0].length;
    	wall[1]=matrix.length;
    	wall[3]=wall[2]=-1;
    	go(Out, matrix, wall, 0, 0, 0);
    	return Out;
    }
    
      private void go(List<Integer> store,int [][] matrix,int [] wall,int index,int x,int y)
      {
    	  switch(index)
    	  {
    	      case 0:
    	      {
    	    	  while(y<wall[0])
    	    	  {
    	    		  store.add(matrix[x][y]);
    	    		  ++y;
    	    	  }
    	    	  --y;
    	    	  wall[3]+=1;
    	    	  if(x+1<wall[1])
    	    		  go(store, matrix, wall, 1, x+1, y);
    	      }
    		  break;
    	      case 1:
    	      {
    	    	  while(x<wall[1])
    	    	  {
    	    		  store.add(matrix[x][y]);
    	    		  ++x;
    	    	  }
    	    	  --x;
    	    	  wall[0]-=1;
    	    	  if(y-1>wall[2])
    	    		  go(store, matrix, wall, 2, x, y-1);
    	      }
    		  break;
    	      case 2:
    	      {
    	    	  while(y>wall[2])
    	    	  {
    	    		  store.add(matrix[x][y]);
    	    		  --y;
    	    	  }
    	    	  ++y;
    	    	  wall[1]-=1;
    	    	  if(x-1>wall[3])
    	    		  go(store, matrix, wall, 3, x-1, y);
    	      }
    		  break;
    	      case 3:
    	      {
    	    	  while(x>wall[3])
    	    	  {
    	    		  store.add(matrix[x][y]);
    	    		  --x;
    	    	  }
    	    	  ++x;
    	    	  wall[2]+=1;
    	    	  if(y+1<wall[0])
    	    		  go(store, matrix, wall, 0, x, y+1);
    	      }
    		  break;
    		  default:
    			  break;
    	  }
      }
}