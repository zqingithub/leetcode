import java.util.LinkedList;
import java.util.Queue;
public class Solution {
	private class Pos
	{
		int x;
		int y;
		Pos(int x,int y)
		{
			this.x=x;
			this.y=y;
		}
	}
    public int numIslands(char[][] grid) {
    	if(grid.length==0||grid[0].length==0)
    		return 0;
    	int outcome=0;
    	Queue<Pos> bfs=new LinkedList<Pos>();
    	int row=grid.length,vol=grid[0].length;
    	Pos search[]=new Pos[]{new Pos(-1,0),new Pos(1,0),
    	new Pos(0,-1),new Pos(0,1)};
    	for(int i=0;i<row;++i)
    		for(int j=0;j<vol;++j)
    		{
    			if(grid[i][j]=='1')
    			{
    				++outcome;
    				grid[i][j]='0';
    				bfs.add(new Pos(i,j));
    				while(!bfs.isEmpty())
    				{
    					Pos temp=bfs.poll();
    					int x,y;
    					for(Pos sPos:search)
    					{
    						x=temp.x+sPos.x;
    						y=temp.y+sPos.y;
    						if(x>=0&&x<row&&y>=0&&y<vol&&grid[x][y]=='1')
    						{
    							grid[x][y]='0';
    							bfs.add(new Pos(x,y));
    						}
    					}
    				}
    			}
    		}
    	return outcome;
    }
}
