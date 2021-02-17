typedef pair<int,int> PII;  //{dist, nodeIdx}

class Solution {
        
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) 
    {
        vector<PII> adj[3000];
        for (auto e:edges)
        {
            adj[e[0]].push_back({e[1], e[2]+1});
            adj[e[1]].push_back({e[0], e[2]+1});
        }
        
        priority_queue<PII, vector<PII>, greater<>>pq;
        pq.push({0, 0});
        
        vector<int>dist(3000, INT_MAX/2);
        vector<int>resolved(3000);
        
        while (!pq.empty())
        {
            auto [d, cur] = pq.top();
            pq.pop();
            
            if (resolved[cur]==1)
                continue;
            resolved[cur] = 1;
            dist[cur] = d;
            
            for (auto [next, len]: adj[cur])
            {
                if (resolved[next]==1) continue;
                if (maxMoves >= d+len)
                    pq.push({d+len, next});
            }
        }
        
        int count = 0;
        for (auto e: edges)
        {
            int a = e[0], b = e[1], cnt = e[2];            
            int sum = 0;
            if (resolved[a]) sum += maxMoves-dist[a];
            if (resolved[b]) sum += maxMoves-dist[b];
            count += min(sum, cnt);
        }
        
        for (int i=0; i<n; i++)
            if (resolved[i])
                count += 1;
        
        return count;
    }
};
