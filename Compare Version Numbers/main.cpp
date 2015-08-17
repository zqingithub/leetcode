#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2)
    {
        version1+=".";
        version2+=".";
        string::size_type index1=0,index2=0,temp1,temp2;
        string temps1,temps2;
        while(true)
        {
            temp1=version1.find(".",index1);
            if(temp1==string::npos)
            {
                temps1="";
            }
            else
            {
                temps1=version1.substr(index1,temp1-index1);
                index1=temp1+1;
            }
            temp2=version2.find(".",index2);
            if(temp2==string::npos)
            {
                temps2="";
            }
            else
            {
                temps2=version2.substr(index2,temp2-index2);
                index2=temp2+1;
            }
            if(temps1.size()==0&&temps2.size()==0)
                return 0;
            if(temps1.size()<temps2.size())
                temps1=string(temps2.size()-temps1.size(),'0')+temps1;
            else
                temps2=string(temps1.size()-temps2.size(),'0')+temps2;
            if(temps1>temps2)
                return 1;
            if(temps1<temps2)
                return -1;
        }
    }
};

int main()
{
    Solution temp;
    temp.compareVersion("1.0", "1");
    return 0;
}