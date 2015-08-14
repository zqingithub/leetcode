#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if(s.size()!=t.size())
            return false;
        vector<int> sumS(26,0);
        vector<int> sumT(26,0);
        for(int i=s.size()-1;i>=0;--i)
        {
            ++sumS[s[i]-'a'];
            ++sumT[t[i]-'a'];
        }
        return sumS==sumT;
    }
};

int main()
{
    return 0;
}
