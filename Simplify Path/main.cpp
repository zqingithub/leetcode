#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path)
	{
		if(path[path.size()-1]!='/')
			path+="/";
		vector<string> simple;
		int index=1;
		while(index<path.size())
		{
			int next=path.find('/',index);
			string temp=path.substr(index,next-index);
			index=next+1;
			if(temp==".")
				continue;
			if(temp=="..")
			{
				if(!simple.empty())
					simple.pop_back();
				continue;
			}
			if(temp!="")
				simple.push_back(temp);
		}
		if(simple.empty())
			return "/";
		string temp="";
		for(int i=0;i<simple.size();++i)
			temp+=string("/")+simple[i];
		return temp;
    }
};
int main()
{
	cout<<Solution().simplifyPath("/abc/...")<<endl;
	return 0;
}