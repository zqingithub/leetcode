#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool> > vol(9,vector<bool>(9,false));
        vector<vector<bool> > row(9,vector<bool>(9,false));
        vector<vector<bool> > squar(9,vector<bool>(9,false));
        for(int i=0;i<9;++i)
        {
            for(int j=0;j<9;++j)
            {
                if(board[i][j]!='.')
                {
                    int temp=board[i][j]-'1';
                    if(vol[j][temp]||row[i][temp]||squar[(i/3)*3+(j/3)][temp])
                        return false;
                    vol[j][temp]=row[i][temp]=squar[(i/3)*3+(j/3)][temp]=true;
                }
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}
