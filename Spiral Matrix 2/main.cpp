#include<iostream>
#include<vector>
using namespace std;

struct step
{
    int dx;
    int dy;
    step(const int dx,const int dy):dx(dx),dy(dy){}
};
class Solution {
public:
    vector<vector<int> > generateMatrix(int n)
    {
        step steps[4]={step(0,1),step(1,0),step(0,-1),step(-1,0)};
        int walls[4]={n-1,n-1,0,0};
        int add[4]={-1,-1,1,1};
        int derect=0;
        bool state[4]={true,true,true,true};
        state[derect]=false;
        vector<vector<int> > outcome(n,vector<int>(n,0));
        int x=0,y=0;
        for(int i=1;i<=n*n;++i)
        {
            outcome[x][y]=i;
            if(!((y<walls[0]||state[0])&&(x<walls[1]||state[1])&&(y>walls[2]||state[2])&&(x>walls[3]||state[3])))
            {
                walls[(derect+3)%4]+=add[((derect+3)%4)];
                state[derect]=true;
                derect=(derect+1)%4;
                state[derect]=false;
            }
            x+=steps[derect].dx;
            y+=steps[derect].dy;
        }
        return outcome;
    }
};

int main()
{
    Solution temp;
    temp.generateMatrix(3);
    return 0;
}
