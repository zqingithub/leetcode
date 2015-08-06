#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > outcome;
        vector<int> store;
        recCom(outcome, k, n, 1, store);
        return outcome;
    }
private:
    void recCom(vector<vector<int> > &outcome,const int k,const int n,const int index,vector<int> &store)
    {
        if(k==0&&n==0)
        {
            outcome.push_back(store);
            return;
        }
        if(k==0)
        {
            return;
        }
        for(int i=index;i<=9&&i<=n;++i)
        {
            store.push_back(i);
            recCom(outcome, k-1, n-i, i+1, store);
            store.pop_back();
        }
    }
};

int main()
{
    return 0;
}