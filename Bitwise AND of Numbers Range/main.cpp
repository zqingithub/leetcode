class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
    	int move=0;
    	while(m!=n)
    	{
    		++move;
    		m>>=1;
    		n>>=1;
    	}
    	return m<<move;
    }
};
int main()
{
	return 0;
}



