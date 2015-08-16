#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height)
    {
        vector<int> maxLeft(height.size(),0);
        vector<int> maxRight(height.size(),0);
        int max=0,temp;
        for(int i=0;i<height.size();++i)
        {
            temp=i;
            while(temp-1>=0&&height[temp-1]>=height[i])temp=maxLeft[temp-1];
            maxLeft[i]=temp;
        }
        for(int i=height.size()-1;i>=0;--i)
        {
            temp=i;
            while(temp+1<height.size()&&height[temp+1]>=height[i])temp=maxRight[temp+1];
            maxRight[i]=temp;
            if((maxRight[i]-maxLeft[i]+1)*height[i]>max)
                max=(maxRight[i]-maxLeft[i]+1)*height[i];
        }
        return max;
    }
};

int main()
{
    return 0;
}