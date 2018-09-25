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
        unordered_set<int>visitedStops;
        unordered_set<int>visitedRoutes;
        q.push({S,0});
        
        while (!q.empty())
        {
            int curStop = q.front().first;
            int step = q.front().second;
            q.pop();
            
            for (int route: stop2routes[curStop])
            {                
                if (visitedRoutes.find(route)!=visitedRoutes.end())
                    continue;
                visitedRoutes.insert(route);
                
                for (int nextStop: routes[route])
                {
                    if (nextStop==T) return step+1;
                    if (visitedStops.find(nextStop)!=visitedStops.end())
                        continue;
                    visitedStops.insert(nextStop);
                    q.push({nextStop,step+1});
                }
            }            
        }
        return -1;
    }
};
