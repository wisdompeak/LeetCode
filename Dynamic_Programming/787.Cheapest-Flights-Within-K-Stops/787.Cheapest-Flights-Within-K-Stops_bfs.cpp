class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) 
    {
        vector<vector<vector<int>>>graph(n);
        for (auto flight: flights)
            graph[flight[0]].push_back({flight[1], flight[2]}) ;

        auto visited = vector<vector<int>>(n, vector<int>(K+2, INT_MAX/2));
        visited[src][0] = 0;
        multiset<vector<int>>Set;
        Set.insert({0, 0, src});

        while (!Set.empty())
        {
            int cost = (*Set.begin())[0];
            int step = (*Set.begin())[1];
            int cur = (*Set.begin())[2];
            Set.erase(Set.begin());

            if (cur==dst) return cost;
            if (step == K+1) continue;

            for (auto ticket: graph[cur])
            {
                if (cost + ticket[1] < visited[ticket[0]][step+1])
                {
                    visited[ticket[0]][step+1] = cost + ticket[1];
                    Set.insert({cost+ticket[1], step+1, ticket[0]});
                }
            }
        }

        return -1;
        
    }
};
