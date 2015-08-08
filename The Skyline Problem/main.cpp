#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

struct edge
{
    int x;
    bool isLeft;
    int height;
    edge(const int x,const bool isLeft,const int height):x(x),isLeft(isLeft),height(height){}
    bool operator < (const edge &e) const
    {
        if(x<e.x)
            return true;
        if(x>e.x)
            return false;
        if(isLeft==e.isLeft)
        {
            if(isLeft)
                return height>e.height;
            else
                return height<e.height;
        }
        else
        {
            return isLeft;
        }
    }
};

class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        vector<pair<int,int> > outcome;
        if(buildings.size()==0)
            return outcome;
        vector<edge> Edges;
        vector<vector<int> >::iterator ite=buildings.begin();
        multiset<int> storeHeight;
        for(;ite!=buildings.end();++ite)
        {
            Edges.push_back(edge((*ite)[0],true,(*ite)[2]));
            Edges.push_back(edge((*ite)[1],false,(*ite)[2]));
        }
        sort(Edges.begin(),Edges.end());
        storeHeight.insert(0);
        for(vector<edge>::size_type i=0;i<Edges.size();++i)
        {
            if(Edges[i].isLeft)
            {
                if(Edges[i].height>*storeHeight.rbegin())
                {
                   outcome.push_back(make_pair(Edges[i].x,Edges[i].height));
                }
                storeHeight.insert(Edges[i].height);
            }
            else
            {
                if(Edges[i].height==*storeHeight.rbegin())
                {
                    storeHeight.erase(storeHeight.find(Edges[i].height));
                    if(Edges[i].height!=*storeHeight.rbegin())
                        outcome.push_back(make_pair(Edges[i].x,*storeHeight.rbegin()));
                }
                else
                {
                    storeHeight.erase(storeHeight.find(Edges[i].height));
                }
            }
        }
        return outcome;
    }
};

int main()
{
    return 0;
}
