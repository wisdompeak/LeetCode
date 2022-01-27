class Solution:
    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        if (n==1): return [0]
        if (n==2): return [0,1]
    
        degree = [0]*n
        Neighbor = [[] for i in range(n)];
        for edge in edges:
            degree[edge[0]]+=1
            degree[edge[1]]+=1
            Neighbor[edge[0]].append(edge[1])
            Neighbor[edge[1]].append(edge[0])
        
        q = collections.deque()
        for i in range(n):
            if degree[i]==1:
                q.append(i)
                
        count = 0        
        while (q):
            L = len(q)
            for i in range(L):
                x = q.popleft()
                count+=1
                for y in Neighbor[x]:
                    degree[y]-=1
                    if degree[y]==1:
                        q.append(y)
            if count+len(q)==n:
                result = []
                while (q): result.append(q.popleft())
                return result
        
