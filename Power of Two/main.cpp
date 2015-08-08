#include<iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n)
    {
        if(n<0)
            return false;
        int count=0;
        while(n!=0)
        {
            ++count;
            n=(n-1)&n;
        }
        return count==1;
    }
};

int main()
{
    return 0;
}