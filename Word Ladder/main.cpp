#include<iostream>
#include<unordered_set>
#include<string>
#include<queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) 
	{
		if(beginWord.size()!=endWord.size())
			return 0;
		if(wordDict.find(beginWord)==wordDict.end())
			return 0;
		queue<string> myque;
		myque.push(beginWord);
		unordered_set<string> state;
		state.insert(beginWord);
		const string sign="0";
		myque.push(sign);
		int count=1;
		const int size=beginWord.size();
		while(!myque.empty())
		{
			string temp=myque.front();
			myque.pop();
			if(sign==temp)
			{
				if(!myque.empty())
				{
					++count;
					myque.push(sign);
				}
			}
			else
			{
				if(temp==endWord)
					return count;
				else
				{
					for(int i=0;i<size;++i)
					{
						string change=temp;
						for(char c='a';c<='z';++c)
						{
							change[i]=c;
							if(wordDict.find(change)!=wordDict.end()&&state.find(change)==state.end())
							{
								myque.push(change);
								state.insert(change);
							}
						}
					}
							
				}
			}
		}
		return 0;

    }
};

int main()
{
	return 0;
}