#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums;
        vector<char> operators;
        int num=0;
        for(int i=0;i<input.length();++i)
        {
            if(input[i]>='0'&&input[i]<='9')
            {
                num=num*10+input[i]-'0';
            }
            else
            {
                nums.push_back(num);
                num=0;
                operators.push_back(input[i]);
            }
        }
        nums.push_back(num);
        return recDif(0, nums.size()-1, nums, operators);
    }
private:
    vector<int> recDif(const int s,const int e,const vector<int> &nums,const vector<char> &operators)
    {
        vector<int> outcome,right,left;
        if(s==e)
        {
            outcome.push_back(nums[s]);
            return outcome;
        }
        for(int i=s;i<e;++i)
        {
            left=recDif(s, i, nums, operators);
            right=recDif(i+1, e, nums, operators);
            for(int j=0;j<left.size();++j)
            {
                for(int k=0;k<right.size();++k)
                {
                    outcome.push_back(value(left[j], right[k], operators[i]));
                }
            }
        }
        return outcome;
    }
    int value(const int a,const int b,char oper)
    {
        switch (oper)
        {
            case '+':
                return a+b;
            case '-':
                return a-b;
            default:
                return a*b;
        }
    }
};

int main()
{
    
}
