#include<iostream>
#include<queue>
using namespace std;

class Stack {
public:
    // Push element x onto stack.
    Stack()
    {
        no=0;
    }
    void push(int x) {
        myque[no].push(x);
        storeTop=x;
    }
    
    // Removes the element on top of the stack.
    void pop() {
        int index=(no+1)%2;
        while(myque[no].size()>1)
        {
            myque[index].push(myque[no].front());
            myque[no].pop();
        }
        if(myque[index].size()>0)
            storeTop=myque[index].back();
        myque[no].pop();
        no=index;
    }
    
    // Get the top element.
    int top() {
        return storeTop;
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return myque[no].empty();
    }
private:
    queue<int> myque[2];
    int no;
    int storeTop;
};

int main()
{
    return 0;
}
