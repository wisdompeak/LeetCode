class Solution:
    def numBusesToDestination(self, routes, S, T):
        """
        :type routes: List[List[int]]
        :type S: int
        :type T: int
        :rtype: int
        """
        if S==T: return 0
        Map = collections.defaultdict(list) #stop->routeIdx
        for i in range(len(routes)):
            for k in routes[i]:
                Map[k].append(i)
                
        q = collections.deque([(S,0)])
        RouteVisited = set()
        count = 0
        while len(q)>0:
            stop,step = q.popleft()
            for routeIdx in Map[stop]:
                if routeIdx in RouteVisited: continue
                RouteVisited.add(routeIdx)
                for NextStop in routes[routeIdx]:
                    if NextStop==T: return step+1
                    q.append((NextStop,step+1))
        return -1
