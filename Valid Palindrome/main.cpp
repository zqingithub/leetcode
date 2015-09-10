#include<iostream>
#include<string>
#include<cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) 
	{
		if(s.empty())
			return true;
		int l=0,r=s.size()-1;
		while(l<r)
		{
			while(l<r&&!isalnum(s[l]))++l;
			while(l<r&&!isalnum(s[r]))--r;
			if(tolower(s[l])!=tolower(s[r]))
				return false;
			++l;
			--r;
		}
		return true;
    }
};

int main()
{
	return 0;
}