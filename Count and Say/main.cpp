#include<iostream>
#include<string>
#include<stringstream>
using namespace std;

class Solution {
public:
    string countAndSay(int n)
    {
        if(n==0)
            return "";
        if(n==1)
            return "1";
        string outcome="1";
        for(int i=2;i<=n;++i)
        {
            outcome=create(outcome);
        }
        return outcome;
    }
private:
    string create(const string &s)
    {
        stringstream outcome;
        char value=s[0];
        int count=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]==value)
                ++count;
            else
            {
                outcome<<count<<value;
                count=1;
                value=s[i];
            }
        }
        outcome<<count<<value;
        return outcome.str();
    }
};

int main()
{
    return 0;
}