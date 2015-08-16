#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b)
    {
        string temp1=a.size()>b.size()?string(a.size()-b.size(),'0')+b:string(b.size()-a.size(),'0')+a;
        string &temp2=a.size()>b.size()?a:b;
        int sign=0;
        for(int i=temp2.size()-1;i>=0;--i)
        {
            int temp=temp1[i]-'0'+temp2[i]-'0'+sign;
            temp1[i]=temp%2+'0';
            sign=temp/2;
        }
        if(sign==1)
            return string(1,'1')+temp1;
        else
            return temp1;
        
    }
};

int main()
{
    Solution temp;
    temp.addBinary("11", "1");
    return 0;
}