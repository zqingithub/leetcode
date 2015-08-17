#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int index=m+n-1,pos1=m-1,pos2=n-1;
        while(pos1>=0&&pos2>=0)
        {
            if(nums1[pos1]>nums2[pos2])
            {
                nums1[index]=nums1[pos1];
                --pos1;
            }
            else
            {
                nums1[index]=nums2[pos2];
                --pos2;
            }
            --index;
        }
        if(pos2>=0)
        {
            while(pos2>=0)
            {
                nums1[index]=nums2[pos2];
                --index;
                --pos2;
            }
        }
    }
};

int main()
{
    return 0;
}