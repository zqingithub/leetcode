class Solution:
    # @return an integer
    def totalNQueens(self, n):
        state=[True]*n
        record=[None]*n
        return self.minSolve(n,0,state,record)
        
    def minSolve(self,n,index,state,record):
        if index==n:
            return 1
        Sum=0
        for x in range(0,n):
            if state[x]:
                for k in range(0,index):
                    if abs(index-k)==abs(x-record[k]):
                        break
                else:
                    record[index]=x
                    state[x]=False
                    Sum+=self.minSolve(n, index+1, state, record)
                    state[x]=True
        return Sum

print Solution().totalNQueens(4)