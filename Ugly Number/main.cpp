#include<iostream>
using namespace std;

class Solution
{
    public:
    bool isUgly(int num)
    {
        if(0==num)
            return false;
        int div[]={2,3,5};
        int temp;
        for(int i=0;i<3;++i)
        {
            temp=num/div[i];
            while(temp*div[i]==num)
            {
                num=num/div[i];
                temp=num/div[i];
            }
        }
        return num==1;
    }

};

int main()
{
    Solution test;
    test.isUgly(0);
    return 0;
}
