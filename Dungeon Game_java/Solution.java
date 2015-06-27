public class Solution {
    public int calculateMinimumHP(int[][] dungeon) 
    {
    	int row=dungeon.length,vol=dungeon[0].length,temp;
    	dungeon[row-1][vol-1]=dungeon[row-1][vol-1]>0?0:-dungeon[row-1][vol-1];
    	for(int i=row-2;i>=0;--i)
    	{
    		temp=dungeon[i+1][vol-1]-dungeon[i][vol-1];
    		dungeon[i][vol-1]=temp>0?temp:0;
    	}
    	for(int i=vol-2;i>=0;--i)
    	{
    		temp=dungeon[row-1][i+1]-dungeon[row-1][i];
    		dungeon[row-1][i]=temp>0?temp:0;
    	}
    	for(int i=row-2;i>=0;--i)
    		for(int j=vol-2;j>=0;--j)
    		{
    			temp=dungeon[i+1][j]<dungeon[i][j+1]?dungeon[i+1][j]:dungeon[i][j+1];
    			temp=temp-dungeon[i][j];
    			dungeon[i][j]=temp>0?temp:0;
    		}
    	return dungeon[0][0]+1;
    }
}