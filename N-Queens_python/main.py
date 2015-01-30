class Solution:
    # @return a list of lists of string
    def solveNQueens(self, n):
        state=[True]*n
        record=[None]*n
        out=[]
        self.minSolve(n,0,state,record,out)
        return out
        
    def minSolve(self,n,index,state,record,out):
        if index==n:
            temp=[]
            for x in record:
                st=['.']*n
                st[x]='Q'
                temp.append("".join(st))
            out.append(temp)
            return
        for x in range(0,n):
            if state[x]:
                for k in range(0,index):
                    if abs(index-k)==abs(x-record[k]):
                        break
                else:
                    record[index]=x
                    state[x]=False
                    self.minSolve(n, index+1, state, record, out)
                    state[x]=True

print Solution().solveNQueens(4)