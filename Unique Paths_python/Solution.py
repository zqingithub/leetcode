class Solution:
    # @return an integer
    def uniquePaths(self, m, n):
        store=[[1]*n]*m
        for i in range(1,m):
            for k in range(1,n):
                store[i][k]=store[i-1][k]+store[i][k-1]
        return store[m-1][n-1]