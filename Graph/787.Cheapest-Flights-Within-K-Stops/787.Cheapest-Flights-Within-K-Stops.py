class Solution:
    def findCheapestPrice(self, n, flights, src, dst, K):
        """
        :type n: int
        :type flights: List[List[int]]
        :type src: int
        :type dst: int
        :type K: int
        :rtype: int
        """
        dp = [math.inf for _ in range(n)]
        dp[src] = 0
        for k in range(K+1):
            dp_temp = dp[:]
            for (a,b,cost) in flights:
                dp[b] = min(dp[b], dp_temp[a]+cost)    
        return dp[dst] if dp[dst]!=math.inf else -1
        
