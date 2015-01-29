class Solution:
    # @param x, a float
    # @param n, a integer
    # @return a float
    def pow(self, x, n):
        if n==0:
            return 1
        return pow(x,n/2)*pow(x,n-n/2)
    
print Solution().pow(2, 3)