class Solution:
    # @return a string
    def __init__(self):
        self.factor=[1]*10
        for i in range(1,len(self.factor)):
            self.factor[i]=self.factor[i-1]*i
            
    def getPermutation(self, n, k):
        left=range(1,n+1)
        Out=""
        for i in range(0,n):
            temp=k//self.factor[n-i-1]
            k=k%self.factor[n-i-1]
            if k==0:
                temp-=1
            Out=Out+("%d"%left[temp]) 
            left.remove(left[temp])
        return Out
        
     
    
print Solution().getPermutation(3, 3)