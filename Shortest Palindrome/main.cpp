#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s)
    {
        if(s.size()==0)
            return "";
        string target=s+"#";
        for(int i=s.size()-1;i>=0;--i)
        {
            target.push_back(s[i]);
        }
        target.push_back('#');
        int index=KMP(target);
        if(index<s.size())
        {
            target=target.substr(s.size()+1,s.size()-index);
        }
        else
        {
            target="";
        }
        return target+s;
    }
private:
    int KMP(const string &target)
    {
        int size=target.size();
        int *next=new int[size+1];
        int prt=0,index=-1;
        next[0]=-1;
        while(prt<size)
        {
            if(index<0||target[index]==target[prt])
            {
                next[++prt]=++index;
            }
            else
            {
                index=next[index];
            }
        }
        int outcome=next[size-1];
        delete [] next;
        return outcome;
    }
};

int main()
{
    Solution temp;
    cout<<temp.shortestPalindrome("abaC")<<endl;
    return 0;
}
