#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 class Solution
 {    
     public:
     vector<string> binaryTreePaths(TreeNode* root)
     {
         vector<string> outcome;
         int index=0, work=0,next=1;
         vector<vector<TreeNode *> > board(2);
         vector<string> mid;
         if(NULL==root)
         {
             return outcome;
         }
         board[work].push_back(root);
         mid.push_back(num2string(root->val));
         while(!board[work].empty())
         {
             for(int i=0;i<board[work].size();++i)
             {
                 if(board[work][i]->left!=NULL)
                 {
                    board[next].push_back(board[work][i]->left);
                    mid.push_back(mid[index]+"->"+num2string(board[work][i]->left->val));
                 }
                 if(board[work][i]->right!=NULL)
                 { 
                     board[next].push_back(board[work][i]->right);
                     mid.push_back(mid[index]+"->"+num2string(board[work][i]->right->val));
                 }
                 if(board[work][i]->left==NULL && board[work][i]->right==NULL)
                 {
                     outcome.push_back(mid[index]);
                 }
                 ++index;
	     }
	     board[work].clear();
	     work=(work+1)%2;
	     next=(next+1)%2;
         }
	 return outcome;
     }

     private:
      
     string num2string(int num)
     {
         string outcome;
	 string sign;
	 if(num<0)
	 {
	   num=-num;
	   sign=sign+'-';
	 }
         do
         {
             outcome.push_back(num%10-0+'0');
             num=num/10;
         }while(num!=0);
	 return sign+string(outcome.rbegin(),outcome.rend());
     }

 };

int main()
{
  TreeNode test(125);
  Solution mySolu;
  mySolu.binaryTreePaths(&test);
  return 0;
}
