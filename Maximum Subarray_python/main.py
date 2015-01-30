class Solution:
    # @param A, a list of integers
    # @return an integer
    def maxSubArray(self, A):
        pre=A[0]
        Max=pre
        for i in range(1,len(A)):
            if pre>0:
                pre+=A[i]
            else:
                pre=A[i]
            if pre>Max:
                Max=pre
        return Max