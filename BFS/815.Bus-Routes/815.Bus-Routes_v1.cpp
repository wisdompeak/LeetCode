class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) 
    {
        if (S==T) return 0;
        
        unordered_map<int,vector<int>>stop2routes;
        for (int i=0; i<routes.size(); i++)        
            for (int j=0; j<routes[i].size(); j++)
                stop2routes[routes[i][j]].push_back(i);
        
        queue<pair<int,int>>q;
        unordered_set<int>visitedRoutes;
        unordered_set<int>visitedStops;
        for (auto route: stop2routes[S])
        {
            q.push({route,1});
            visitedRoutes.insert(route);
            visitedStops.insert(S);
        }            
        
        while (!q.empty())
        {
            int curRoute = q.front().first;
            int step = q.front().second;
            q.pop();
            
            for (int stop: routes[curRoute])
            {
                if (stop==T) return step;
                if (visitedStops.find(stop)!=visitedStops.end()) continue;
                    
                visitedStops.insert(stop);
                for (int nextRoute: stop2routes[stop])
                {
                    if (visitedRoutes.find(nextRoute)!=visitedRoutes.end())
                        continue;
                    visitedRoutes.insert(nextRoute);
                    q.push({nextRoute,step+1});
                }
            }            
        }
        return -1;
    }
};
