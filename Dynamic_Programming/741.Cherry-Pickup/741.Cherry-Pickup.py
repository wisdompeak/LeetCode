class Solution:
    def cherryPickup(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        N = len(grid)
        dp = [[[-math.inf for _ in range(N+1)] for _ in range(N+1)] for _ in range(N+1)]        
        dp[0][1][0],dp[0][1][1],dp[1][0][0],dp[1][0][1] = 0,0,0,0
        
        for i in range(1,N+1):
            for j in range(1,N+1):                
                for x in range(1,N+1):
                    y = i+j-x
                    if y<1 or y>N: continue                    
                    if grid[i-1][j-1]==-1 or grid[x-1][y-1]==-1: continue
                    dp[i][j][x] = max(dp[i-1][j][x],dp[i][j-1][x],dp[i-1][j][x-1],dp[i][j-1][x-1])                    
                    if i==x and j==y:
                        dp[i][j][x] += grid[i-1][j-1]
                    else:
                        dp[i][j][x] += grid[i-1][j-1]+grid[x-1][y-1]
        return max(dp[N][N][N],0)
                    
        
