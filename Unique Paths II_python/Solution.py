class Solution:
    # @param obstacleGrid, a list of lists of integers
    # @return an integer
    def uniquePathsWithObstacles(self, obstacleGrid):
        store=[]
        for i in range(0,len(obstacleGrid)):
            store.append([1]*len(obstacleGrid[0]))
            
        if obstacleGrid[0][0]==1:
            store[0][0]=0
        
        for i in range(1,len(obstacleGrid[0])):
            if obstacleGrid[0][i]==1:
                store[0][i]=0
            else:
                store[0][i]=store[0][i-1]
              
        for i in range(1,len(obstacleGrid)):
            if obstacleGrid[i][0]==1:
                store[i][0]=0
            else:
                store[i][0]=store[i-1][0]
                      
        for i in range(1,len(obstacleGrid)):
            for k in range(1,len(obstacleGrid[0])):
                if obstacleGrid[i][k]==1:
                    store[i][k]=0
                else:
                    store[i][k]=store[i-1][k]+store[i][k-1]
        return store[-1][-1]

