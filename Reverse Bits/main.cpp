typedef unsigned int uint32_t;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {		
		uint32_t outcome=0,sign;		
		for(sign=1;sign!=0;sign<<=1)		
		{			
			outcome<<=1;			
			outcome|=n&1;			
			n>>=1;		
		}		
		return outcome;
    }
};
int main()

{
	return 0;
}