#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) 
	{
		if(s1.length()!=s2.length())
			return false;
		if(1==s1.length())
			return s1==s2;
		string temp1=s1,temp2=s2;
		sort(temp1.begin(),temp1.end());
		sort(temp2.begin(),temp2.end());
		if(temp1!=temp2)
			return false;
		int Leng=s1.length();
		for(int L=1;L<Leng;++L)
		{
			if(isScramble(s1.substr(0,L),s2.substr(0,L))
				&&isScramble(s1.substr(L,Leng-L),s2.substr(L,Leng-L)))
				return true;
			if(isScramble(s1.substr(0,L),s2.substr(Leng-L,L))
				&&isScramble(s1.substr(L,Leng-L),s2.substr(0,Leng-L)))
				return true;
		}
		return false;
    }
};

int main()
{
	return 0;
}