class Solution:
    # @param A, a list of integers
    # @return a boolean
    def canJump(self, A):
        Max=0
        for i in range(0,len(A)) :
            if i<=Max and i+A[i]>Max:
                Max=i+A[i]
        if Max>=len(A)-1:
            return True
        else:
            return False