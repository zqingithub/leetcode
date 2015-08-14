#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s)
    {
        int count=0;
        int i=s.size()-1;
        while(i>=0&&s[i]==' ')--i;
        for(;i>=0;--i)
        {
            if(s[i]!=' ')
                ++count;
            else
                return count;
        }
        return count;
    }
};

int main()
{
    return 0;
}