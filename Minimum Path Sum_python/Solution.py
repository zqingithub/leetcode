class Solution:
    # @param grid, a list of lists of integers
    # @return an integer
    def minPathSum(self, grid):
        store=[]
        for i in range(0,len(grid)):
            store.append([1]*len(grid[0]))
        store[0][0]=grid[0][0]
        for i in range(1,len(grid[0])):
            store[0][i]=grid[0][i]+store[0][i-1]
        for i in range(1,len(grid)):
            store[i][0]=grid[i][0]+store[i-1][0]
        for i in range(1,len(grid)):
            for k in range(1,len(grid[0])):
                if store[i-1][k]<store[i][k-1]:
                    store[i][k]=store[i-1][k]
                else:
                    store[i][k]=store[i][k-1]
                store[i][k]+=grid[i][k]
        return store[-1][-1]