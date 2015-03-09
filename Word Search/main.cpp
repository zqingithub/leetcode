#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word)
    {
    	bool ** state=new bool*[board.size()];
    	for(int i=0;i<board.size();++i)
    	{
    		state[i]=new bool[board.back().size()];
    		memset(state[i],0,sizeof(bool)*board.back().size());
    	}
    	bool temp=false;
    	for(int x=0;x<board.size();++x)
    	{
    		for(int y=0;y<board.back().size();++y)
    			if(rec(board,word,0,state,x,y))
    			{
    				temp=true;
    				break;
    			}
    		if(temp)
    			break;
    	}
    	for(int i=0;i<board.size();++i)
    		delete [] state[i];
    	delete [] state;
    	return temp;
    }
private:
    bool rec(vector<vector<char> >&board,string & word,int k,bool ** state,int x,int y)
    {
    	if(k==word.size())
    		return true;
    	if(x==board.size()||x<0||y==board.back().size()||y<0)
    		return false;
    	if(state[x][y]||board[x][y]!=word[k])
    		return false;
    	state[x][y]=true;
    	if(rec(board,word,k+1,state,x-1,y))
    		return true;
    	if(rec(board,word,k+1,state,x+1,y))
    		return true;
    	if(rec(board,word,k+1,state,x,y-1))
    		return true;
    	if(rec(board,word,k+1,state,x,y+1))
    		return true;
    	state[x][y]=false;
    	return false;
    }
};

int main()
{
	return 0;
}



