#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct unit
{
    bool isOper;
    char oper;
    int value;
    unit(char oper):isOper(true),oper(oper){}
    unit(int value):isOper(false),value(value){}
};
class Solution {
public:
    int calculate(string s)
    {
        stack<char> oper;
        queue<unit> express;
        bool haveNum=false;
        int size=s.size();
        int value=0;
        for(int i=0;i<size;++i)
        {
            char temp=s[i];
            switch (temp)
            {
                case '(':
                {
                    oper.push('(');
                    break;
                }
                case ')':
                {
                    if(haveNum)
                    {
                        express.push(unit(value));
                        value=0;
                        haveNum=false;
                    }
                    while(oper.top()!='(')
                    {
                        express.push(unit(oper.top()));
                        oper.pop();
                    }
                    oper.pop();
                    break;
                }
                case '+':
                {
                    if(haveNum)
                    {
                        express.push(unit(value));
                        value=0;
                        haveNum=false;
                    }
                    while(!oper.empty()&&oper.top()!='(')
                    {
                        express.push(unit(oper.top()));
                        oper.pop();
                    }
                    oper.push('+');
                    break;
                }
                case '-':
                {
                    if(haveNum)
                    {
                        express.push(unit(value));
                        value=0;
                        haveNum=false;
                    }
                    while(!oper.empty()&&oper.top()!='(')
                    {
                        express.push(unit(oper.top()));
                        oper.pop();
                    }
                    oper.push('-');
                    break;
                }
                case ' ':
                {
                    continue;
                }
                default:
                {
                    value=value*10+temp-'0';
                    haveNum=true;
                }
            }
        }
        if(haveNum)
            express.push(unit(value));
        if(!oper.empty())
        {
            while(!oper.empty())
            {
                express.push(oper.top());
                oper.pop();
            }
        }
        stack<int> com;
        while(!express.empty())
        {
            if(express.front().isOper)
            {
                int num1=com.top();
                com.pop();
                int num2=com.top();
                com.pop();
                if (express.front().oper=='+')
                {
                    com.push(num1+num2);
                }
                else
                {
                    com.push(num2-num1);
                }
            }
            else
                com.push(express.front().value);
            express.pop();
        }
        return com.top();
    }
};

int main()
{
    Solution temp;
    temp.calculate("(1-(3-4))");
    return 0;
}
