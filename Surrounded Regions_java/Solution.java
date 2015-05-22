import java.util.Stack;
public class Solution {
    public void solve(char[][] board) 
    {
    	if(board==null||board.length==0||board[0].length==0)
    		return;
    	int r=board.length,v=board[0].length;
    	for(int i=0;i<r;++i)
    	{
    		if(board[i][0]=='O')
    			search(board,i,0);
    		if(board[i][v-1]=='O')
    			search(board,i,v-1);
    	}
    	for(int i=0;i<v;++i)
    	{
    		if(board[0][i]=='O')
    			search(board,0,i);
    		if(board[r-1][i]=='O')
    			search(board,r-1,i);
    	}
    	for(int i=0;i<r;++i)
    		for(int j=0;j<v;++j)
    		{
    			if(board[i][j]=='O')
    				board[i][j]='X';
    			if(board[i][j]==sign)
    				board[i][j]='O';
    		}
    	
    }
    private void search(char[][] board,int x,int y)
    {
    	Stack<pos> mysk=new Stack<pos>();
    	board[x][y]=sign;
    	mysk.add(new pos(x,y));
    	pos temp;
    	while(!mysk.isEmpty())
    	{
    		temp=mysk.pop();
    		x=temp.x;
    		y=temp.y;
        	if(x-1>=0&&board[x-1][y]=='O')
        	{
        		board[x-1][y]=sign;
        		mysk.add(new pos(x-1,y));
        	}
        	if(x+1<board.length&&board[x+1][y]=='O')
        	{
        		board[x+1][y]=sign;
        		mysk.add(new pos(x+1,y));
        	}
        	if(y-1>=0&&board[x][y-1]=='O')
        	{
        		board[x][y-1]=sign;
        		mysk.add(new pos(x,y-1));
        	}
        	if(y+1<board[0].length&&board[x][y+1]=='O')
        	{
        		board[x][y+1]=sign;
        		mysk.add(new pos(x,y+1));
        	}
    		
    	}
    }
    private class pos
    {
    	public int x;
    	public int y;
    	pos(int x,int y)
    	{
    		this.x=x;
    		this.y=y;
    	}
    }
    private static final char sign='+';
}