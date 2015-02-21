import math
class Solution:
    # @param x, an integer
    # @return an integer
    def sqrt(self, x):
        cur=1
        pre=0
        while math.fabs(cur-pre)>0.00001:
            pre=cur
            cur=cur/2.0+x/(cur*2.0) 
        return int(cur)
    
print Solution().sqrt(3)