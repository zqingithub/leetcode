#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class WordDic
{
public:
    bool isWord;
    bool isRecord;
    vector<WordDic*> next;
    WordDic()
    {
        isWord=false;
        isRecord=false;
        for(int i=0;i<26;++i)
        {
            next.push_back(NULL);
        }
    }
    static void insert(WordDic *root,const string word)
    {
        int size=word.length();
        WordDic * prt=root;
        for(int i=0;i<size;++i)
        {
            int index=word[i]-'a';
            if(prt->next[index]==NULL)
            {
                prt->next[index]=new WordDic();
            }
            prt=prt->next[index];
        }
        prt->isWord=true;
    }
};
struct Pos
{
    int x;
    int y;
    int no;
    Pos(const int x,const int y)
    {
        this->x=x;
        this->y=y;
        no=0;
    }
};

void dfs(WordDic * root,const int x,const int y,vector<vector<char> >&board,vector<string> &outcome)
{
    if(root->next[board[y][x]-'a']==NULL)
        return;
    int width=board[0].size();
    int length=board.size();
    vector<vector<bool> > isVisit;
    for(int i=0;i<length;++i)
    {
        isVisit.push_back(vector<bool>());
        for(int j=0;j<width;++j)
        {
            isVisit[i].push_back(false);
        }
    }
    isVisit[y][x]=true;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    stack<WordDic*> recordPrt;
    stack<Pos> recordBoard;
    string word="";
    word.push_back(board[y][x]);
    recordPrt.push(root->next[board[y][x]-'a']);
    if(recordPrt.top()->isWord&&!recordPrt.top()->isRecord)
    {
        outcome.push_back(word);
        recordPrt.top()->isRecord=true;
    }
    recordBoard.push(Pos(x,y));
    while(!recordBoard.empty())
    {
        Pos tempPos=recordBoard.top();
        if(tempPos.no>3)
        {
            recordBoard.pop();
            isVisit[tempPos.y][tempPos.x]=false;
            recordPrt.pop();
            word.pop_back();
            continue;
        }
        WordDic * tempPrt=recordPrt.top();
        int tempx=tempPos.x+dx[tempPos.no],tempy=tempPos.y+dy[tempPos.no];
        recordBoard.top().no+=1;
        if(tempx<width&&tempx>=0&&tempy<length&&tempy>=0&&!isVisit[tempy][tempx]&&tempPrt->next[board[tempy][tempx]-'a']!=NULL)
        {
            recordBoard.push(Pos(tempx,tempy));
            isVisit[tempy][tempx]=true;
            recordPrt.push(tempPrt->next[board[tempy][tempx]-'a']);
            word.push_back(board[tempy][tempx]);
            if(recordPrt.top()->isWord&&!recordPrt.top()->isRecord)
            {
                outcome.push_back(word);
                recordPrt.top()->isRecord=true;
            }
        }
    }
    
}

class Solution {
public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        vector<string> outcome;
        if(words.size()==0||board.size()==0||board[0].size()==0)
            return outcome;
        WordDic *root=new WordDic();
        for(int i=words.size()-1;i>=0;--i)
        {
            WordDic::insert(root, words[i]);
        }
        for(int i=board[0].size()-1;i>=0;--i)
        {
            for(int j=board.size()-1;j>=0;--j)
            {
                dfs(root, i, j, board, outcome);
            }
        }
        return outcome;
    }
};

int main()
{
    vector<vector<char> >board;
    board.push_back(vector<char>());
    board[0].push_back('a');
    board[0].push_back('a');
    vector<string> words;
    words.push_back("a");
    Solution temp;
    vector<string> outcome=temp.findWords(board, words);
    return 0;
}