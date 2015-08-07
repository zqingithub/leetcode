#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int outcome=(C-A)*(D-B)+(G-E)*(H-F);
        if(E>C||A>G||F>D||B>H)
            return outcome;
        return outcome-((min(C,G))-max(A,E))*(min(D,H)-max(B,F));
    }
};

int main()
{
    return 0;
}
