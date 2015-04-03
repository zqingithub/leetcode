#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution 
{
public:
    vector<string> restoreIpAddresses(string s) 
	{
		out.clear();
		rec(s,1,0);
		return out;
    }
private:
	string store[4];
	vector<string> out;
	void rec(const string & s,const int index,const int pos)
	{
		if(index>4)
		{
			string temp=store[0];
			for(int i=1;i<4;++i)
				temp+=string(".")+store[i];
			out.push_back(temp);
			return;
		}
		int Ip=0;
		for(int i=pos;i<pos+3&&i<s.size();++i)
		{
			Ip=Ip*10+s[i]-'0';
			int len=s.size()-i-1;
			if(len<=3*(4-index)&&len>=4-index&&Ip>=0&&Ip<=255)
			{
				if('0'!=s[pos]||i==pos)
				{
					store[index-1]=s.substr(pos,i-pos+1);
				    rec(s,index+1,i+1);
				}
				if(0==Ip)
					break;
			}
		}
	}
};

int main()
{
	return 0;
}