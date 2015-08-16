#include<iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n<3)
            return n;
        int pre1=1,pre2=2,temp;
        for(int i=2;i<n;++i)
        {
            temp=pre2;
            pre2+=pre1;
            pre1=temp;
        }
        return pre2;
    }
};

int main()
{
    return 0;
}