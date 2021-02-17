typedef pair<int,int> PII; 

class Solution {
    int dist[3000];
    int resolved[3000];
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) 
    {
        vector<PII> adj[3000];  // {nextNode, weight}
        for (auto e: edges)
        {
            adj[e[0]].push_back({e[1], e[2]+1});
            adj[e[1]].push_back({e[0], e[2]+1});
        }
        
        priority_queue<PII, vector<PII>, greater<>>pq;  // {dist, nodeIdx}
        pq.push({0,0});        
        
        while (!pq.empty())
        {
            auto [d, cur] = pq.top();
            pq.pop();
            if (resolved[cur]) continue;
            resolved[cur] = 1;
            dist[cur] = d;
                        
            for (auto [next, weight] : adj[cur])
            {
                if (resolved[next]) continue;
                if (d+weight <= maxMoves)
                    pq.push({d+weight, next});
            }            
        }
        
        int count = 0;
        for (auto e: edges)
        {
            int a = e[0], b = e[1];
            int sum = 0;
            if (resolved[a]) sum += maxMoves - dist[a];
            if (resolved[b]) sum += maxMoves - dist[b];
            count += min(sum, e[2]);
        }
        
        for (int i=0; i<n; i++)
            if (resolved[i])
                count++;
        
        return count;
        
    }
};
