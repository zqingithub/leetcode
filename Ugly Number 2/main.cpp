#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    int nthUglyNumber(int n) 
    {
        vector<int> Ugly(n);
        Ugly[0]=1;
        int factor[3]={2,3,5};
        int prt[3]={0,0,0};
        int tempMin[3]={2,3,5};
        for(int i=1;i<n;++i)
        {
            Ugly[i]=findMin(tempMin[0],tempMin[1],tempMin[2]);
            for(int j=0;j<3;++j)
            {
                if(tempMin[j]==Ugly[i])
                {
                    tempMin[j]=Ugly[++(prt[j])]*factor[j];
                }
            }
        }
        return Ugly[n-1];
    }

    private:
    int findMin(const int a,const int b,const int c)
    {
        int temp=a>b?b:a;
        return temp>c?c:temp;
    }
};

int main()
{
    return 0;
}
