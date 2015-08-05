#include<iostream>
#include<vector>
using namespace std;

#define Max(a,b) ((a)>(b)?(a):(b))
class Solution {
public:
    int rob(vector<int>& nums) {
        int size=nums.size();
        if(size==0)
            return 0;
        int max=nums[0],preMaxNo=0,preMaxYes=0;
        for(int i=2;i<size-1;++i)
        {
            int temp=preMaxNo;
            preMaxNo=Max(preMaxNo, preMaxYes);
            preMaxYes=temp+nums[i];
        }
        max+=Max(preMaxYes, preMaxNo);
        preMaxNo=preMaxYes=0;
        for(int i=1;i<size;++i)
        {
            int temp=preMaxNo;
            preMaxNo=Max(preMaxNo, preMaxYes);
            preMaxYes=temp+nums[i];
        }
        max=Max(max, Max(preMaxYes, preMaxNo));
        return max;
    }
};

int main()
{
    return 0;
}
