using AI3 = array<int,3>;
using PII = pair<int,int>;
class Solution {
    vector<PII>next[500];
public:
    int shortestPathWithHops(int n, vector<vector<int>>& edges, int source, int destination, int k) 
    {
        for (auto& edge: edges)
        {
            int a = edge[0], b = edge[1], w = edge[2];
            next[a].push_back({b,w});
            next[b].push_back({a,w});
        }
        priority_queue<AI3, vector<AI3>, greater<>>pq;
        pq.push({0, source, k});

        vector<vector<int>>dist(n, vector<int>(k+1, INT_MAX/2));

        while (!pq.empty())
        {
            auto [d, cur, t] = pq.top();
            pq.pop();
            if (dist[cur][t]!=INT_MAX/2) continue;
            dist[cur][t] = d;
            if (cur==destination) return d;

            for (auto [nxt, weight]:next[cur])
            {
                if (dist[nxt][t]==INT_MAX/2)
                    pq.push({d+weight, nxt, t});
                if (t>=1 && dist[nxt][t-1]==INT_MAX/2)
                    pq.push({d, nxt, t-1});
            }
        }
        return -1;        
    }
};
