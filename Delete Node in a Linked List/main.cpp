#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        ListNode * temp=node->next;
        node->next=temp->next;
        delete temp;
    }
};

int main()
{
    return 0;
}
