class Solution:
    def shortestPathLength(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: int
        """
        N = len(graph)
        allVisitedStatus = (1<<N)-1
        
        q = collections.deque()
        visited = set()
        for i in range(N):
            q.append((i,1<<i))
            visited.add((i,1<<i))
        
        step = 0
        while (q):
            L = len(q)
            step += 1
            for i in range(L):
                node,status = q.popleft()
                for nextNode in graph[node]:         
                    if status|(1<<nextNode)==allVisitedStatus:
                        return step
                    if (nextNode,status|(1<<nextNode)) in visited: 
                        continue
                    q.append((nextNode,status|(1<<nextNode)))
                    visited.add((nextNode,status|(1<<nextNode)))        
        return 0
