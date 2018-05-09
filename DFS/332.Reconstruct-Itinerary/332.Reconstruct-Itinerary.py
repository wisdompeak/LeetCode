class Solution:
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        Map = collections.defaultdict(list)
        for a,b in sorted(tickets)[::-1]:
            Map[a].append(b)            
        path = []
        def DFS(start):
            while Map[start]:
                DFS(Map[start].pop())              
            path.append(start)    
        DFS('JFK')
        return path[::-1]
