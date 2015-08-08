#include<iostream>
using namespace std;

class Solution {
public:
    int countDigitOne(int n)
    {
        int count=0,i;
        long multi=1;
        while(multi<=n)
        {
            i=n/multi;
            count+=(i+8)/10*multi;
            if(i%10==1) count+=n%multi+1;
            multi*=10;
        }
        return count;
    }
};

int main()
{
    return 0;
}
