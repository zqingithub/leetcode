#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0)
            return false;
        int row=0,vol=matrix[0].size()-1;
        while(row<matrix.size()&&vol>=0)
        {
            if(matrix[row][vol]==target)
                return true;
            if(matrix[row][vol]<target)
                ++row;
            else
                --vol;
        }
        bool outcome;
        return outcome;
    }
};

int main()
{
    return 0;
}