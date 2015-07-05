#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses,
    		vector<pair<int, int> >& prerequisites)
	{
    	vector<int> outcome;
    	vector<vector<int> > adj;
    	vector<int> inDegree;
    	queue<int> isZero;
    	for(int i=0;i<numCourses;++i)
    	{
    		adj.push_back(vector<int>());
    		inDegree.push_back(0);
    	}
    	for(int i=prerequisites.size()-1;i>=0;--i)
    	{
    		adj[prerequisites[i].second].push_back(prerequisites[i].first);
            ++inDegree[prerequisites[i].first];
    	}
    	for(int i=0;i<numCourses;++i)
    		if(inDegree[i]==0)
    			isZero.push(i);
    	int count=0;
    	while(!isZero.empty())
    	{
    		int temp=isZero.front();
    		isZero.pop();
    		outcome.push_back(temp);
    		++count;
    		for(int i=adj[temp].size()-1;i>=0;--i)
    		{
    			--inDegree[adj[temp][i]];
    			if(inDegree[adj[temp][i]]==0)
    				isZero.push(adj[temp][i]);
    		}
    	}
    	if(count!=numCourses)
    		outcome.clear();
    	return outcome;
    }
};

int main()
{
	return 0;
}
